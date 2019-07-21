/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_event_utils_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 10:53:43 by chorange          #+#    #+#             */
/*   Updated: 2019/06/13 20:43:17 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	edit_mouse_pressed_4(char *func, t_rtv1 *rtv1)
{
	if (!ft_strcmp(func, "Texture1"))
		rtv1->selected->tex = 0;
	else if (!ft_strcmp(func, "Texture2"))
		rtv1->selected->tex = 1;
	else if (!ft_strcmp(func, "Texture3"))
		rtv1->selected->tex = 2;
	else if (!ft_strcmp(func, "Texture4"))
		rtv1->selected->tex = 3;
	else if (!ft_strcmp(func, "Texture5"))
		rtv1->selected->tex = 4;
	else if (!ft_strcmp(func, "Rand Color"))
	{
		rtv1->selected->tex = -1;
		rtv1->selected->rgb = (t_rgb){rand() % 255, 
							rand() % 255, rand() % 255};
	}
}

void	edit_mouse_pressed_3(char *func, t_rtv1 *rtv1)
{
	if (!ft_strcmp(func, "Smoothness+") && rtv1->selected->reflective < 1.0)
	{
		rtv1->selected->smoothness += 0.1;
		if (rtv1->selected->smoothness > 1.0)
			rtv1->selected->smoothness = 1.0;
	}
	else if (!ft_strcmp(func, "Smoothness-"))
	{
		rtv1->selected->smoothness -= 0.1;
		if (rtv1->selected->smoothness < 0.0)
			rtv1->selected->smoothness = 0.0;
	}
	else 
		edit_mouse_pressed_4(func, rtv1);
}

void	edit_mouse_pressed_2(char *func, t_rtv1 *rtv1)
{
	if (!ft_strcmp(func, "Angle+"))
		rtv1->selected->angle += 0.1;
	else if (!ft_strcmp(func, "Angle-"))
		rtv1->selected->angle -= 0.1;
	else if (!ft_strcmp(func, "Specular+"))
		rtv1->selected->specular += 20.0;
	else if (!ft_strcmp(func, "Specular-") && rtv1->selected->specular > 0.0)
		rtv1->selected->specular -= 20.0;
	else if (!ft_strcmp(func, "Reflective+") && rtv1->selected->reflective < 1.0)
	{
		rtv1->selected->reflective += 0.1;
		if (rtv1->selected->reflective > 1.0)
			rtv1->selected->reflective = 1.0;
	}
	else if (!ft_strcmp(func, "Reflective-"))
	{
		rtv1->selected->reflective -= 0.1;
		if (rtv1->selected->reflective < 0.0)
			rtv1->selected->reflective = 0.0;
	}
	else
		edit_mouse_pressed_3(func, rtv1);
}

void	edit_mouse_pressed_1(int button, char *func, t_rtv1 *rtv1)
{
	if (!ft_strcmp(func, "Refractive+"))
		rtv1->selected->refractive += 0.1;
	else if (!ft_strcmp(func, "Refractive-"))
	{	
		rtv1->selected->refractive -= 0.1;
		if (rtv1->selected->refractive < 1.0)
			rtv1->selected->refractive = 1.0;
	}
	else if (!ft_strcmp(func, "Radius+"))
		rtv1->selected->radius += 0.1;
	else if (!ft_strcmp(func, "Radius-") && rtv1->selected->radius > 0.1)
		rtv1->selected->radius -= 0.1;
	else
		edit_mouse_pressed_2(func, rtv1);
}

void	edit_mouse_pressed(int button, int x, int y, t_rtv1 *rtv1)
{
	int		pressed_button;
	char	func[64];

	pressed_button = LIBUI_IsButtonPressed(x, y, 
			rtv1->edit_buttons, rtv1->c_edit_buttons);
	if (pressed_button == -1)
		return;
	ft_strcpy(func, rtv1->edit_buttons[pressed_button].function);
	if (!ft_strcmp(func, "Transparency+"))
	{	
		rtv1->selected->transparency += 0.1;
		if (rtv1->selected->transparency > 1.0)
			rtv1->selected->transparency = 1.0;
	}
	else if (!ft_strcmp(func, "Transparency-"))
	{	
		rtv1->selected->transparency -= 0.1;
		if (rtv1->selected->transparency < 0.0)
			rtv1->selected->transparency = 0.0;
	}
	else
		edit_mouse_pressed_1(button, func, rtv1);
}
