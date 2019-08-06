/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:10:50 by chorange          #+#    #+#             */
/*   Updated: 2019/07/31 13:49:46 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		graphics_init_1(t_rtv1 *rtv1)
{
	rtv1->renderer = SDL_CreateRenderer(rtv1->window, -1,
		SDL_RENDERER_ACCELERATED);
	rtv1->rect.x = 0;
	rtv1->rect.y = 0;
	rtv1->rect.w = CW;
	rtv1->rect.h = CH;
	rtv1->c_buttons = 0;
	rtv1->c_edits = 0;
	rtv1->c_lists = 0;
}

void		libui_init_1(t_rtv1 *rtv1)
{
	libui_newbutton((t_but_constr){20, 20, "New Sphere", "New Sphere",
		0x0000ff55}, rtv1->buttons, &(rtv1->c_buttons));
	libui_newbutton((t_but_constr){20, 60, "New Cylinder", "New Cylinder",
		0x0000ff55}, rtv1->buttons, &(rtv1->c_buttons));
	libui_newbutton((t_but_constr){20, 100, "New Cone", "New Cone",
		0x0000ff55}, rtv1->buttons, &(rtv1->c_buttons));
	libui_newbutton((t_but_constr){20, 140, "New Plane", "New Plane",
		0x0000ff55}, rtv1->buttons, &(rtv1->c_buttons));
	libui_newbutton((t_but_constr){20, 500, "New PointL", "New PointL",
		0x0000ff55}, rtv1->buttons, &(rtv1->c_buttons));
	libui_newbutton((t_but_constr){20, 280, "Delete Object", "Delete Object",
		0x0000ff55}, rtv1->buttons, &(rtv1->c_buttons));
	libui_newbutton((t_but_constr){20, 340, "Save Scene", "Save Scene",
		0x0000ff55}, rtv1->buttons, &(rtv1->c_buttons));
}

void		libui_init_2(t_rtv1 *rtv1)
{
	libui_newbutton((t_but_constr){20, 400+250, "Selector", "Selector",
		0x0000ff55}, rtv1->buttons, &rtv1->c_buttons);
	libui_newbutton((t_but_constr){20, 400+300, "Edit", "Edit",
		0x0000ff55}, rtv1->buttons, &rtv1->c_buttons);
	libui_newbutton((t_but_constr){20, 400+380, "Ambient", "Ambient",
		0x0000ff55}, rtv1->buttons, &rtv1->c_buttons);
	libui_newbutton((t_but_constr){20, 400+430, "Soft Shadows",
		"Soft Shadows", 0x0000ff55}, rtv1->buttons, &rtv1->c_buttons);
	libui_newbutton((t_but_constr){20, 400+480, "Export BMP",
		"Export BMP", 0x0000ff55}, rtv1->buttons, &rtv1->c_buttons);
	libui_newedit((t_edit_constr){200, 240, "Name", "Name",
		0x00550000}, rtv1->edits, &rtv1->c_edits);
	libui_newbutton((t_but_constr){200, 300, "Save As", "Save As",
		0x0000ff55}, rtv1->buttons, &rtv1->c_buttons);
}

void		graphics_init(t_rtv1 *rtv1)
{
	rtv1->selected_light = NULL;
	rtv1->guide_on = 0;
	rtv1->shift_pressed = 0;
	rtv1->dropped_list = -1;
	rtv1->active_edit = -1;
	rtv1->edit_window_active = 0;
	rtv1->selector_window_active = 0;
	rtv1->next_win_ID = 2;
	rtv1->scene.advanced = 0;
	rtv1->scene.soft = 0;
	SDL_Init(SDL_INIT_VIDEO);
	rtv1->surface = SDL_CreateRGBSurface(0, CW, CH, 32, 0, 0, 0, 0);
	rtv1->ui = SDL_CreateRGBSurface(0, 400, CH, 32, 0, 0, 0, 0);
	rtv1->tmp = SDL_CreateRGBSurface(0, 400, CH, 32, 0, 0, 0, 0);
	SDL_FillRect(rtv1->tmp, &((SDL_Rect){0, 0, 400, CH}), 0x00FFFF00);
	rtv1->window = SDL_CreateWindow("RT", 400, 200,
		CW + 400, CH, SDL_WINDOW_SHOWN);
	graphics_init_1(rtv1);
	libui_init_1(rtv1);
	libui_init_2(rtv1);
	kernel_init(rtv1);
}
