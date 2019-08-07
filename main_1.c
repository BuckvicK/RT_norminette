/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 19:25:19 by cocummin          #+#    #+#             */
/*   Updated: 2019/07/31 14:18:22 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		provider_condition_switch(t_rtv1 *rtv1, SDL_Event ev)
{
	if (ev.type == SDL_WINDOWEVENT)
		provider_8_windowevent(rtv1, ev);
	else if (ev.type == SDL_KEYDOWN)
		key_pressed(ev.key.keysym.sym, rtv1);
	else if (ev.type == SDL_KEYUP)
		key_release(ev.key.keysym.sym, rtv1);
	else if (ev.type == SDL_MOUSEBUTTONDOWN)
		provider_9_mousebuttondown(rtv1, ev);
	else if (ev.type == SDL_MOUSEBUTTONUP)
		provider_10_mousebuttonup(rtv1, ev);
	else if (ev.type == SDL_MOUSEMOTION)
		provider_11_mousemotion(rtv1, ev);
	else if (ev.type == SDL_MOUSEWHEEL)
		provider_12_mousewheel(rtv1, ev);
}

void		provider(t_rtv1 *rtv1)
{
	SDL_Event	ev;

	provider_1(rtv1);
	provider_2(rtv1);
	provider_3(rtv1);
	provider_4(rtv1);
	provider_5(rtv1);
	provider_6(rtv1);
	provider_7(rtv1);
	while(SDL_PollEvent(&ev))
		provider_condition_switch(rtv1, ev);
	SDL_Delay(10);
}
