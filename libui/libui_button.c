/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui_button.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 10:46:33 by chorange          #+#    #+#             */
/*   Updated: 2019/07/31 14:03:16 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_libui_button		libui_createbutton(t_but_constr input)
{
	t_libui_button	button;
	SDL_Surface		*text;
	TTF_Font		*font;

	button.is_pressed = 0;
	button = (t_libui_button){.x = input.x, .y = input.y};
	ft_strcpy(button.function, input.function);
	button.surface = SDL_CreateRGBSurface(0, 100, 30, 32, 0, 0, 0, 0);
	SDL_FillRect(button.surface, &((SDL_Rect){0, 0, 100, 30}), input.color);
	button.pressed = SDL_CreateRGBSurface(0, 100, 30, 32, 0, 0, 0, 0);
	SDL_FillRect(button.pressed, &((SDL_Rect){0, 0, 100, 30}),
		input.color - 0x11111100);
	TTF_Init();
	font = TTF_OpenFont("lato/Lato-Bold.ttf", 14);
	text = TTF_RenderText_Blended(font, input.text, (SDL_Color){0, 0, 0, 0});
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_BlitSurface(text, &((SDL_Rect){ -8, -8, 100, 30}),
		button.surface, NULL);
	SDL_BlitSurface(text, &((SDL_Rect){ -8, -8, 100, 30}),
		button.pressed, NULL);
	SDL_FreeSurface(text);
	return (button);
}

void				libui_newbutton(t_but_constr button,
						t_libui_button *buttons, int *c_buttons)
{

	buttons[*c_buttons] = libui_createbutton(button);
	(*c_buttons)++;
}

int					libui_isbuttonpressed(int x, int y,
						t_libui_button *buttons, int c_buttons)
{
	int		i;

	i = 0;
	while (i < c_buttons)
	{
		if ((buttons[i]).x < x && (buttons[i]).y < y &&
			(buttons[i]).y + 30 > y && (buttons[i]).x + 100 > x)
		{
			buttons[i].is_pressed = 1;
			return (i);
		}
		i++;
	}
	return (-1);
}
