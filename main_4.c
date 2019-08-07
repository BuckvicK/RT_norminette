/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 19:25:19 by cocummin          #+#    #+#             */
/*   Updated: 2019/07/31 14:18:22 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		provider_5(t_rtv1 *rtv1)
{
	int		i;

	i = 0;
	if (rtv1->edit_window_active)
	{
		while (i < rtv1->c_edit_buttons)
		{
			SDL_BlitSurface((rtv1->edit_buttons[i].is_pressed ?
				rtv1->edit_buttons[i].pressed :
				rtv1->edit_buttons[i].surface),
				&((SDL_Rect){-rtv1->edit_buttons[i].x,
				-rtv1->edit_buttons[i].y, rtv1->edit_buttons[i].x + 100,
				rtv1->edit_buttons[i].y + 30}), rtv1->edit_surface, NULL);
			i++;
		}
		rtv1->edit_texture = SDL_CreateTextureFromSurface(rtv1->edit_renderer,
			rtv1->edit_surface);
		SDL_RenderClear(rtv1->edit_renderer);
		SDL_RenderCopy(rtv1->edit_renderer, rtv1->edit_texture, NULL, NULL);
		SDL_DestroyTexture(rtv1->edit_texture);
		SDL_RenderPresent(rtv1->edit_renderer);
	}
}

void		provider_6_1(t_rtv1 *rtv1, int i)
{
	SDL_BlitSurface((rtv1->selector_buttons[i].is_pressed ?
		rtv1->selector_buttons[i].pressed :
		rtv1->selector_buttons[i].surface),
		&((SDL_Rect){-rtv1->selector_buttons[i].x,
		-rtv1->selector_buttons[i].y,
		rtv1->selector_buttons[i].x + 100,
		rtv1->selector_buttons[i].y + 30}),
		rtv1->selector_surface, NULL);
}

void		provider_6(t_rtv1 *rtv1)
{
	int		i;

	i = 0;
	if (rtv1->selector_window_active)
	{
		while (i < rtv1->c_selector_buttons)
		{
			provider_6_1(rtv1, i);
			i++;
		}
		rtv1->selector_texture = SDL_CreateTextureFromSurface(\
			rtv1->selector_renderer, rtv1->selector_surface);
		SDL_RenderClear(rtv1->selector_renderer);
		SDL_RenderCopy(rtv1->selector_renderer,
			rtv1->selector_texture, NULL, NULL);
		SDL_DestroyTexture(rtv1->selector_texture);
		SDL_RenderPresent(rtv1->selector_renderer);
	}
}

void		provider_7(t_rtv1 *rtv1)
{
	rtv1->ui_tex = SDL_CreateTextureFromSurface(rtv1->renderer, rtv1->ui);
	SDL_RenderClear(rtv1->renderer);
	SDL_RenderCopy(rtv1->renderer, rtv1->screen, NULL, &rtv1->rect);
	SDL_RenderCopy(rtv1->renderer, rtv1->ui_tex, NULL,
		&((SDL_Rect){CH, 0, 400, CH}));
	SDL_DestroyTexture(rtv1->screen);
	SDL_DestroyTexture(rtv1->ui_tex);
	SDL_RenderPresent(rtv1->renderer);
	if (!(rtv1->selected))
		rtv1->selected = &(rtv1->scene.objs[0]);
}
