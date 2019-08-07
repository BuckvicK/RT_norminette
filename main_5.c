/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 19:25:19 by cocummin          #+#    #+#             */
/*   Updated: 2019/07/31 14:18:22 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		provider_8_windowevent(t_rtv1 *rtv1, SDL_Event ev)
{
	if (ev.window.event == 14 && ev.window.windowID == 1)
	{
		if (rtv1->edit_window_active)
			SDL_DestroyWindow(rtv1->edit_window);
		if (rtv1->selector_window_active)
			SDL_DestroyWindow(rtv1->edit_window);
		SDL_DestroyWindow(rtv1->window);
		SDL_Quit();
		exit(1);
	}
	else if (ev.window.event == 14 && 
				ev.window.windowID == rtv1->edit_window_active)
		destroy_edit(rtv1);
	else if (ev.window.event == 14 &&
				ev.window.windowID == rtv1->selector_window_active)
		destroy_scene_selector(rtv1);
}

void		provider_9_mousebuttondown(t_rtv1 *rtv1, SDL_Event ev)
{
	if (ev.window.windowID == 1)
		mouse_pressed(ev.button.button, ev.button.x, ev.button.y, rtv1);
	else if (ev.window.windowID == rtv1->edit_window_active)
		edit_mouse_pressed(ev.button.button, ev.button.x, ev.button.y, rtv1);
	else if (ev.window.windowID == rtv1->selector_window_active)
		selector_mouse_pressed(ev.button.button, ev.button.x,
			ev.button.y, rtv1);
}

void		provider_10_mousebuttonup(t_rtv1 *rtv1, SDL_Event ev)
{
	if (ev.window.windowID == 1)
		mouse_release(ev.button.button, ev.button.x, ev.button.y, rtv1);
	else if (ev.window.windowID == rtv1->edit_window_active)
		edit_mouse_release(ev.button.button, ev.button.x, ev.button.y, rtv1);
	else if (ev.window.windowID == rtv1->selector_window_active)
		selector_mouse_release(ev.button.button, ev.button.x,
			ev.button.y, rtv1);
}

void		provider_11_mousemotion(t_rtv1 *rtv1, SDL_Event ev)
{
	if (ev.window.windowID == 1)
		mouse_move(ev.motion.x, ev.motion.y, rtv1);
}

void		provider_12_mousewheel(t_rtv1 *rtv1, SDL_Event ev)
{
	if (ev.window.windowID == 1)
		mouse_wheel(ev.wheel.y, rtv1);
}
