/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_event_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 10:53:43 by chorange          #+#    #+#             */
/*   Updated: 2019/06/13 20:43:17 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	edit_mouse_release_1(t_rtv1 *rtv1)
{
	int	i;

	i = 0;
	while (i < rtv1->c_selector_buttons)
	{
		(rtv1->selector_buttons)[i].is_pressed = 0;
		i++;
	}
    i = 0;
	while (i < rtv1->c_edit_buttons)
	{
		(rtv1->edit_buttons)[i].is_pressed = 0;
		i++;
	}
}

void	edit_mouse_release(int button, int x, int y, t_rtv1 *rtv1)
{
	int	i;
	int	j;

	x = y;
	button = x;
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
}
