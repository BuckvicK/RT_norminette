/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 12:11:52 by chorange          #+#    #+#             */
/*   Updated: 2019/07/31 13:06:56 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_list_item_addr	list_utils(t_rtv1 *rtv1, int x, int y)
{
	t_list_item_addr	ret;

	ret = libui_islistpressed(x - CH, y, rtv1->lists, rtv1->c_lists);
	return (ret);
}

void				mouse_release_1(t_rtv1 *rtv1, int button, int x, int y)
{
	button = x + y;
	rtv1->left_mouse_pressed = 0;
	rtv1->right_mouse_pressed = 0;
	rtv1->mid_mouse_pressed = 0;
	rtv1->arrow = -1;
}

int					mouse_release(int button, int x, int y, t_rtv1 *rtv1)
{
	int		i;
	int		j;

	mouse_release_1(rtv1, button, x, y);
	i = 0;
	while (i < rtv1->c_buttons)
	{
		(rtv1->buttons)[i].is_pressed = 0;
		i++;
	}
	i = 0;
	while (i < rtv1->c_lists)
	{
		j = 0;
		while (j < rtv1->lists[i].c_items)
		{
			(rtv1->lists)[i].items[j].is_pressed = 0;
			j++;
		}
		i++;
	}
	return (0);
}

/*
** double		cos_a;			arr[0]
** double		sin_a;			arr[1]
** double		one_min_cos_a;	arr[2]
** double		xy;				arr[3]
** double		xz;				arr[4]
** double		yz;				arr[5]
*/
t_vector			rot_v(t_vector P, t_vector ax, double a)
{
	t_vector	ret;
	double		m[9];
	double		arr[6];

	arr[0] = cos(a);
	arr[1] = sin(a);
	arr[2] = 1 - arr[0];
	arr[3] = ax.x * ax.y;
	arr[4] = ax.x * ax.z;
	arr[5] = ax.y * ax.z;
	m[0] = arr[0] + arr[2] * ax.x * ax.x;
	m[1] = arr[2] * arr[3] - arr[1] * ax.z;
	m[2] = arr[2] * arr[4] + arr[1] * ax.y;
	m[3] = arr[2] * arr[3] + arr[1] * ax.z;
	m[4] = arr[0] + arr[2] * ax.y * ax.y;
	m[5] = arr[2] * arr[5] - arr[1] * ax.x;
	m[6] = arr[2] * arr[4] - arr[1] * ax.y;
	m[7] = arr[2] * arr[5] + arr[1] * ax.x;
	m[8] = arr[0] + arr[2] * ax.z * ax.z;
	ret.x = P.x * m[0] + P.y * m[1] + P.z * m[2];
	ret.y = P.x * m[3] + P.y * m[4] + P.z * m[5];
	ret.z = P.x * m[6] + P.y * m[7] + P.z * m[8];
	return (ret);
}

int					mouse_move(int x, int y, t_rtv1 *rtv1)
{
	int		dx;
	int		dy;

	if (rtv1->right_mouse_pressed)
	{
		dx = x - rtv1->prev_x;
		dy = y - rtv1->prev_y;
		rtv1->scene.view_alpha += atan((double)dy * 0.001);
		rtv1->scene.view_beta += atan((double)dx * 0.001);
	}
	else if (rtv1->left_mouse_pressed)
	{
		dx = x - rtv1->prev_x;
		dy = y - rtv1->prev_y;
		if (rtv1->selected && rtv1->arrow != -1 && !rtv1->selected_light)
		{
			if (rtv1->arrow == 0)
			{
				if (rtv1->selected->type == triangle)
					move_polygonal(0.001 * dx * rtv1->selected_t * (cos(rtv1->scene.view_beta) > 0 ? 1 : -1), 0.0, 0.0, rtv1);
				else
					rtv1->selected->center.x += 0.001 * dx * rtv1->selected_t * (cos(rtv1->scene.view_beta) > 0 ? 1 : -1);
			}
			else if (rtv1->arrow == 1)
			{
				if (rtv1->selected->type == triangle)
					move_polygonal(0.0, -0.001 * dy * rtv1->selected_t ,0.0, rtv1);
				else
					rtv1->selected->center.y -= 0.001 * dy * rtv1->selected_t;
			}
			else if (rtv1->arrow == 2)
			{
				if (rtv1->selected->type == triangle)
					move_polygonal(0.0, 0.0, 0.001 * dx * rtv1->selected_t * (sin(rtv1->scene.view_beta) > 0 ? 1 : -1), rtv1);
				else
					rtv1->selected->center.z += 0.001 * dx * rtv1->selected_t * (sin(rtv1->scene.view_beta) > 0 ? 1 : -1);
			}
			set_arrows_pos(rtv1, 0);
		}
		else if (rtv1->selected_light && rtv1->arrow != -1)
		{
			rtv1->selected_t = vector_length(vector_subt(rtv1->scene.camera.center, rtv1->selected_light->center));
			if (rtv1->arrow == 0)
				rtv1->selected_light->center.x += 0.001 * dx * rtv1->selected_t * (cos(rtv1->scene.view_beta) > 0 ? 1 : -1);
			else if (rtv1->arrow == 1)
				rtv1->selected_light->center.y -= 0.001 * dy * rtv1->selected_t;
			else if (rtv1->arrow == 2)
				rtv1->selected_light->center.z += 0.001 * dx * rtv1->selected_t * (sin(rtv1->scene.view_beta) > 0 ? 1 : -1);
			set_arrows_pos(rtv1, 1);
		}
	}
	else if (rtv1->mid_mouse_pressed)
	{
		dx = x - rtv1->prev_x;
		dy = y - rtv1->prev_y;
		if (!(rtv1->selected))
			rtv1->selected = &(rtv1->scene.objs[0]);
		if (rtv1->selected->type == sphere)
		{
			rtv1->selected->rot.y -= 0.05 * dx;
			rtv1->selected->rot.x += 0.05 * dy;
		}
		else
		{
			if (rtv1->selected && rtv1->arrow != -1)
			{
				if (rtv1->arrow == 0)
				{
					if (rtv1->selected->type == triangle)
						rot_polygonal(0.05 * dy, 0.0, 0.0, rtv1);
					else
						rtv1->selected->dir = vector_normalize(rot(rtv1->selected->dir, (t_vector){0.05 * dy, 0.0, 0.0}));
				}
				else if (rtv1->arrow == 1)
				{
					if (rtv1->selected->type == triangle)
						rot_polygonal(0.0, 0.05 * dx, 0.0, rtv1);
					else
						rtv1->selected->dir = vector_normalize(rot(rtv1->selected->dir, (t_vector){0.0, 0.05 * dx, 0.0}));
				}
				else if (rtv1->arrow == 2)
				{
					if (rtv1->selected->type == triangle)
						rot_polygonal(0.0, 0.0, 0.05 * dy, rtv1);
					else
						rtv1->selected->dir = vector_normalize(rot(rtv1->selected->dir, (t_vector){0.0, 0.0, 0.05 * dy}));
				}
			}
		}
	}
	rtv1->prev_x = x;
	rtv1->prev_y = y;
	return (0);
}

int					key_pressed(int key, t_rtv1 *rtv1)
{
	if (!(rtv1->selected))
		rtv1->selected = &(rtv1->scene.objs[0]);
	if (key == SDLK_ESCAPE)
		exit(1);
	else if (rtv1->active_edit != -1)
		libui_inputletter(key, rtv1->edits, rtv1->active_edit,
			rtv1->shift_pressed);
	else if (key == SDLK_RIGHT)
	{
		rtv1->scene.camera.center.x += 0.5 * cos(rtv1->scene.view_beta);
		rtv1->scene.camera.center.z += 0.5 * sin(rtv1->scene.view_beta);
	}
	else if (key == SDLK_LEFT)
	{
		rtv1->scene.camera.center.x -= 0.5 * cos(rtv1->scene.view_beta);
		rtv1->scene.camera.center.z -= 0.5 * sin(rtv1->scene.view_beta);
	}
	else if (key == SDLK_UP)
		rtv1->scene.camera.center.y += 0.5;
	else if (key == SDLK_DOWN)
		rtv1->scene.camera.center.y -= 0.5;
	else if (key == SDLK_KP_PLUS)
		rtv1->selected->center.z += 0.2;
	else if (key == SDLK_KP_MINUS)
		rtv1->selected->center.z -= 0.2;
	else if (key == SDLK_s)
	{
		if (rtv1->scene.shadows_on == 1)
			rtv1->scene.shadows_on = 0;
		else
			rtv1->scene.shadows_on = 1;
	}
	if (key == 1073742049)
		rtv1->shift_pressed = 1;
	return (0);
}

int					mouse_wheel(int y, t_rtv1 *rtv1)
{
	rtv1->scene.camera.center.x -= y * sin(rtv1->scene.view_beta);
	rtv1->scene.camera.center.z -= y * cos(rtv1->scene.view_beta);
	return (0);
}

int					key_release(int key, t_rtv1 *rtv1)
{
	if (key == 1073742049)
		rtv1->shift_pressed = 0;
	return (0);
}
