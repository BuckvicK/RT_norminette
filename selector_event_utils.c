/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selector_event_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 19:25:19 by cocummin          #+#    #+#             */
/*   Updated: 2019/07/31 14:18:22 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	selector_mouse_pressed_1(t_rtv1 *rtv1, int *id)
{
	*id = get_index_by_id(&rtv1->scene, *id);
	rtv1->selected = &rtv1->scene.objs[*id];
	rtv1->selected_light = NULL;
	set_arrows_pos(rtv1, 0);
}

void	selector_mouse_pressed_2(t_rtv1 *rtv1, int *id)
{
	*id = get_light_index_by_id(&rtv1->scene, *id);
	rtv1->selected_light = &rtv1->scene.lights[*id];
	set_arrows_pos(rtv1, 1);
}

void	selector_mouse_pressed(int button, int x, int y, t_rtv1 *rtv1)
{
    int		pressed_button;
    char	func[64];
    int		id;

	pressed_button = libui_isbuttonpressed(x, y, rtv1->selector_buttons,
		rtv1->c_selector_buttons);
    if (pressed_button == -1)
        return;
    ft_strcpy(func, rtv1->selector_buttons[pressed_button].function);
    id = ft_atoi(func);
	if (ft_strstr(func, "object"))
		selector_mouse_pressed_1(rtv1, &id);
	else if (ft_strstr(func, "light"))
	{
		selector_mouse_pressed_2(rtv1, &id);
	}	
	rtv1->scene.arrows_on = 1;
}

void	selector_mouse_release_1(t_rtv1 *rtv1)
{
	int		i;

	i = 0;
	while (i < rtv1->c_edit_buttons)
	{
		(rtv1->edit_buttons)[i].is_pressed = 0;
		i++;
	}
    i = 0;
	while (i < rtv1->c_selector_buttons)
	{
		(rtv1->selector_buttons)[i].is_pressed = 0;
		i++;
	}
    i = 0;
    while (i < rtv1->c_buttons)
	{
		(rtv1->buttons)[i].is_pressed = 0;
		i++;
	}
}

void	selector_mouse_release(int button, int x, int y, t_rtv1 *rtv1)
{
	int		i;
	int		j;

	button = x + y;
	selector_mouse_release_1(rtv1);
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
}
