/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 19:25:19 by cocummin          #+#    #+#             */
/*   Updated: 2019/07/31 14:18:22 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		provider_4_1(t_rtv1 *rtv1, int i)
{
	SDL_BlitSurface((rtv1->lists[i].items[0].is_pressed ?
		rtv1->lists[i].items[0].pressed :
		rtv1->lists[i].items[0].surface),
		&((SDL_Rect){-rtv1->lists[i].items[0].x,
		-rtv1->lists[i].items[0].y, rtv1->lists[i].items[0].x + 100,
		rtv1->lists[i].items[0].y + 30}), rtv1->ui, NULL);
}

void		provider_4_2(t_rtv1 *rtv1, int i, int j)
{
	SDL_BlitSurface((rtv1->lists[i].items[j].is_pressed ?
		rtv1->lists[i].items[j].pressed :
		rtv1->lists[i].items[j].surface),
		&((SDL_Rect){-rtv1->lists[i].items[j].x,
		-rtv1->lists[i].items[j].y, rtv1->lists[i].items[j].x + 100,
		rtv1->lists[i].items[j].y + 30}), rtv1->ui, NULL);
}

void		provider_4(t_rtv1 *rtv1)
{
	int		i;
	int		j;

	i = 0;
	while (i < rtv1->c_lists)
	{
		provider_4_1(rtv1, i);
		if (rtv1->lists[i].is_dropped)
		{
			j = 1;
			while (j < rtv1->lists[i].c_items)
			{
				provider_4_2(rtv1, i, j);
				j++;
			}
		}
		i++;
	}
}
