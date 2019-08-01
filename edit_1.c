/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 10:53:43 by chorange          #+#    #+#             */
/*   Updated: 2019/06/13 20:43:17 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		edit_2(t_rtv1 *rtv1)
{
	libui_newbutton((t_but_constr){20, 370, "Smoothness+", "Smoothness+",
		0x0000ff55}, rtv1->edit_buttons, &rtv1->c_edit_buttons);
	libui_newbutton((t_but_constr){180, 370, "Smoothness-", "Smoothness-",
		0x0000ff55}, rtv1->edit_buttons, &rtv1->c_edit_buttons);
	libui_newbutton((t_but_constr){340, 20, "Texture1", "Texture1",
		0x0000ff55}, rtv1->edit_buttons, &rtv1->c_edit_buttons);
	libui_newbutton((t_but_constr){340, 70, "Texture2", "Texture2",
		0x0000ff55}, rtv1->edit_buttons, &rtv1->c_edit_buttons);
	libui_newbutton((t_but_constr){340, 120, "Texture3", "Texture3",
		0x0000ff55}, rtv1->edit_buttons, &rtv1->c_edit_buttons);
	libui_newbutton((t_but_constr){340, 170, "Texture4", "Texture4",
		0x0000ff55}, rtv1->edit_buttons, &rtv1->c_edit_buttons);
	libui_newbutton((t_but_constr){340, 220, "Texture5", "Texture5",
		0x0000ff55}, rtv1->edit_buttons, &rtv1->c_edit_buttons);
	libui_newbutton((t_but_constr){340, 270, "Rand Color", "Rand Color",
		0x0000ff55}, rtv1->edit_buttons, &rtv1->c_edit_buttons);
}

void		edit_1(t_rtv1 *rtv1)
{
	libui_newbutton((t_but_constr){20, 170, "Specular+", "Specular+",
		0x0000ff55}, rtv1->edit_buttons, &rtv1->c_edit_buttons);
	libui_newbutton((t_but_constr){180, 170, "Specular-", "Specular-",
		0x0000ff55}, rtv1->edit_buttons, &rtv1->c_edit_buttons);
	libui_newbutton((t_but_constr){20, 220, "Reflective+", "Reflective+",
		0x0000ff55}, rtv1->edit_buttons, &rtv1->c_edit_buttons);
	libui_newbutton((t_but_constr){180, 220, "Reflective-", "Reflective-",
		0x0000ff55}, rtv1->edit_buttons, &rtv1->c_edit_buttons);
	libui_newbutton((t_but_constr){20, 270, "Transparency+", "Transparency+",
		0x0000ff55}, rtv1->edit_buttons, &rtv1->c_edit_buttons);
	libui_newbutton((t_but_constr){180, 270, "Transparency-", "Transparency-",
		0x0000ff55}, rtv1->edit_buttons, &rtv1->c_edit_buttons);
	libui_newbutton((t_but_constr){20, 320, "Refractive+", "Refractive+",
		0x0000ff55}, rtv1->edit_buttons, &rtv1->c_edit_buttons);
	libui_newbutton((t_but_constr){180, 320, "Refractive-", "Refractive-",
		0x0000ff55}, rtv1->edit_buttons, &rtv1->c_edit_buttons);
	edit_2(rtv1);
}

void		edit(t_rtv1 *rtv1)
{
	rtv1->edit_surface = SDL_CreateRGBSurface(0, 640, 480, 32, 0, 0, 0, 0);
	rtv1->edit_window = SDL_CreateWindow("Properties", 1800, 200, 640, 480,
		SDL_WINDOW_SHOWN);
	rtv1->edit_renderer = SDL_CreateRenderer(rtv1->edit_window, -1,
		SDL_RENDERER_ACCELERATED);
	rtv1->c_edit_buttons = 0;
	rtv1->edit_window_active = rtv1->next_win_ID;
	rtv1->next_win_ID++;
	SDL_FillRect(rtv1->edit_surface, &((SDL_Rect){0, 0, 640, 480}),
		0x00FFFF00);
	libui_newbutton((t_but_constr){20, 20, "Radius+", "Radius+", 0x0000ff55},
		rtv1->edit_buttons, &rtv1->c_edit_buttons);
	libui_newbutton((t_but_constr){180, 20, "Radius-", "Radius-", 0x0000ff55},
		rtv1->edit_buttons, &rtv1->c_edit_buttons);
	libui_newbutton((t_but_constr){20, 70, "Angle+", "Angle+", 0x0000ff55},
		rtv1->edit_buttons, &rtv1->c_edit_buttons);
	libui_newbutton((t_but_constr){180, 70, "Angle-", "Angle-", 0x0000ff55},
		rtv1->edit_buttons, &rtv1->c_edit_buttons);
	libui_newbutton((t_but_constr){20, 120, "Radius+", "Radius+", 0x0000ff55},
		rtv1->edit_buttons, &rtv1->c_edit_buttons);
	libui_newbutton((t_but_constr){180, 120, "Radius+", "Radius+",
		0x0000ff55}, rtv1->edit_buttons, &rtv1->c_edit_buttons);
	edit_1(rtv1);
}

