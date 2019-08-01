/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 10:53:43 by chorange          #+#    #+#             */
/*   Updated: 2019/06/13 20:43:17 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	mouse_pressed1(int button, int x, int y,
				t_rtv1 *rtv1, t_libui_button *buttons, int c_buttons)
{
	int		pressed_button;

	if (y < 0)
		return (0);
	if (button == SDL_BUTTON_LEFT)
	{
		pressed_button = libui_isbuttonpressed(x, y, buttons, c_buttons);
		if (pressed_button == -1)
			return (0);
		buttons[pressed_button].is_pressed = 1;
		if (!ft_strcmp(buttons[pressed_button].function, "Radius+"))
			rtv1->selected->radius += 0.1;
		else if (!ft_strcmp(buttons[pressed_button].function, "Radius-"))
			rtv1->selected->radius -= 0.1;
	}
	return (0);
}

static int	mouse_release1(t_libui_button *buttons ,int c_buttons)
{
	int		i;

	i = 0;
	while (i < c_buttons)
	{
		(buttons)[i].is_pressed = 0;
		i++;
	}
	return (0);
}

void		destroy_edit(t_rtv1 *rtv1)
{
	int		i;

	i = 0;
	while (i < rtv1->c_edit_buttons)
	{
		SDL_FreeSurface(rtv1->edit_buttons[i].pressed);
		SDL_FreeSurface(rtv1->edit_buttons[i].surface);
		i++;
	}
	rtv1->c_edit_buttons = 0;
	SDL_FreeSurface(rtv1->edit_surface);
	SDL_DestroyWindow(rtv1->edit_window);
	rtv1->edit_window_active = 0;
}
