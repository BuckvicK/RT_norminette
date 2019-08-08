/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 12:11:52 by chorange          #+#    #+#             */
/*   Updated: 2019/07/31 13:06:56 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		mouse_pressed_1()
{
	return (0);
}

int			mouse_pressed(int button, int x, int y, t_rtv1 *rtv1)
{
	int					pressed_button;
	char				func[64];
	t_list_item_addr	ret;
	int					selected_id;

	rtv1->prev_x = x;
	rtv1->prev_y = y;
	if (y < 0)
		return (0);
	if (button == SDL_BUTTON_LEFT)
	{
		if (x < 1000)
			select_object(rtv1, x, y, &(rtv1->selected));
		else
		{
			pressed_button = libui_isbuttonpressed(x - CH, y, rtv1->buttons, rtv1->c_buttons);
			if (pressed_button == -1)
			{
				ret = list_utils(rtv1, x, y);
				if (ret.item == -1)
				{
					rtv1->active_edit = libui_iseditpressed(x - CH, y, rtv1->edits, rtv1->c_edits);
					if (rtv1->active_edit == -1)
					{
						libui_disactiveall(rtv1->edits, rtv1->c_edits, rtv1->lists, rtv1->c_lists);
						return (0);
					}
				}
				else
				{
					rtv1->active_edit = -1;
					ft_strcpy(func, rtv1->lists[ret.list].items[ret.item].function);
				}
			}
			else
			{
				rtv1->active_edit = -1;
				ft_strcpy(func, rtv1->buttons[pressed_button].function);
			}
			if (!ft_strcmp(func, "New Sphere"))
			{
				new_sphere(rtv1);
				refresh_selector_buttons(rtv1);
			}
			else if (!ft_strcmp(func, "New Cylinder"))
			{
				new_cylinder(rtv1);
				refresh_selector_buttons(rtv1);
			}
			else if (!ft_strcmp(func, "New Cone"))
			{
				new_cone(rtv1);
				refresh_selector_buttons(rtv1);
			}
			else if (!ft_strcmp(func, "New Plane"))
			{
				new_plane(rtv1);
				refresh_selector_buttons(rtv1);
			}
			else if (!ft_strcmp(func, "New PointL"))
			{
				new_point(rtv1);
				refresh_selector_buttons(rtv1);
			}
			else if (!ft_strcmp(func, "New PointD"))
			{
				new_directional(rtv1);
				refresh_selector_buttons(rtv1);
			}
			else if (!ft_strcmp(func, "Delete Object"))
			{
				if (rtv1->selected_light && rtv1->scene.c_lights)
				{
					selected_id = get_light_index_by_id(&rtv1->scene, rtv1->selected_light->id);
					rtv1->scene.lights[selected_id] = rtv1->scene.lights[rtv1->scene.c_lights - 1];
					rtv1->scene.c_lights--;
					rtv1->scene.arrows_on = 0;
					refresh_selector_buttons(rtv1);
					return (0);
				}
				if (!rtv1->scene.c_objs)
					return (0);
				selected_id = (rtv1->selected - &rtv1->scene.objs[0]);
				rtv1->scene.objs[selected_id] = rtv1->scene.objs[rtv1->scene.c_objs - 1];
				rtv1->scene.c_objs--;
				rtv1->scene.arrows_on = 0;
				refresh_selector_buttons(rtv1);
			}
			else if (!ft_strcmp(func, "Save Scene"))
			{	
				save(rtv1, rtv1->scene_file_name);
			}
			else if (!ft_strcmp(func, "Save As"))
			{
				save_as(rtv1);
			}
			else if (!ft_strcmp(func, "Ambient"))
			{
				rtv1->scene.advanced = (rtv1->scene.advanced ? 0 : 1);
			}
			else if (!ft_strcmp(func, "Soft Shadows"))
			{
				rtv1->scene.soft = (rtv1->scene.soft ? 0 : 1);
			}
			else if (!ft_strcmp(func, "Export BMP"))
			{
				IMG_SavePNG(rtv1->surface, "screens/1.png");
			}
			else if (!ft_strcmp(rtv1->buttons[pressed_button].function, "Edit"))
			{	
				if (rtv1->edit_window_active == 0)
					edit(rtv1);
			}
			else if (!ft_strcmp(rtv1->buttons[pressed_button].function, "Selector"))
			{	
				if (rtv1->selector_window_active == 0)
					scene_selector(rtv1);
			}
			else if (!ft_strcmp(func, "lol"))
			{
				if (rtv1->lists[0].is_dropped == 1)
					rtv1->lists[0].is_dropped = 0;
				else
					rtv1->lists[0].is_dropped = 1;
			}
		}
		rtv1->left_mouse_pressed = 1;
	}
	else if (button == SDL_BUTTON_RIGHT)
		rtv1->right_mouse_pressed = 1;
	else if (button == SDL_BUTTON_MIDDLE)
	{
		select_object(rtv1, x, y, &rtv1->selected);
		rtv1->mid_mouse_pressed = 1;
	}
	return (0);
}
