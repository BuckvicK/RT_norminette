/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 19:25:19 by cocummin          #+#    #+#             */
/*   Updated: 2019/07/31 14:18:22 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		provider_1(t_rtv1 *rtv1)
{
	int		h = 0;
	int		fd;
	char	str[501];
	int		rand_suka;

	fd = open("/dev/urandom", O_RDONLY);
	read(fd, str, 501);
	close(fd);
	while (h < 500)
	{
		rand_suka = rand() % 2;
		rtv1->scene.rands[h] = (double)str[h];
		if (rtv1->scene.rands[h] < 0.0000001 ||
				rtv1->scene.rands[h] > -0.0000001)
			rtv1->scene.rands[h] = (double)rand() / 12.58;
		else
			rtv1->scene.rands[h] += rtv1->scene.rands[h + 1] / 59.36;
		rtv1->scene.rands[h] *= rand_suka == 1 ? -1.0 : 1.0;
		while (fabs(rtv1->scene.rands[h]) < 1000.0)
			rtv1->scene.rands[h] *= 10.0;
		while (fabs(rtv1->scene.rands[h]) > 10000.0)
			rtv1->scene.rands[h] /= 10.0;
		h++;
	}
}

void		provider_2(t_rtv1 *rtv1)
{
	rtv1->ret = clEnqueueWriteBuffer(rtv1->command_queue, rtv1->memobj,
		CL_TRUE, 0, CW * CH * 4, (char *)rtv1->surface->pixels,
			0, NULL, NULL);
	rtv1->ret = clSetKernelArg(rtv1->kernel, 0, sizeof(cl_mem),
		(void *)&rtv1->memobj);
	rtv1->ret = clEnqueueWriteBuffer(rtv1->command_queue,
			rtv1->utils_memobj, CL_TRUE, 0,
			sizeof(t_scene), &(rtv1->scene), 0, NULL, NULL);
	rtv1->ret = clSetKernelArg(rtv1->kernel, 1,
			sizeof(cl_mem), (void *)&rtv1->utils_memobj);
	rtv1->ret = clEnqueueNDRangeKernel(rtv1->command_queue, rtv1->kernel, 1,
			NULL, &rtv1->global_work_size, NULL, 0, NULL, NULL);
	rtv1->ret = clEnqueueReadBuffer(rtv1->command_queue, rtv1->memobj,
			CL_TRUE, 0, CW * CH * 4, (void *)rtv1->surface->pixels,
				0, NULL, NULL);
	rtv1->screen = SDL_CreateTextureFromSurface(rtv1->renderer,
		rtv1->surface);
	SDL_BlitSurface(rtv1->tmp, NULL, rtv1->ui, NULL);
}

void		provider_3(t_rtv1 *rtv1)
{
	int		i;

	i = 0;
	while (i < rtv1->c_buttons)
	{
		SDL_BlitSurface((rtv1->buttons[i].is_pressed ?
			rtv1->buttons[i].pressed : rtv1->buttons[i].surface),
			&((SDL_Rect){-rtv1->buttons[i].x, -rtv1->buttons[i].y,
			rtv1->buttons[i].x + 100, rtv1->buttons[i].y + 30}),
			rtv1->ui, NULL);
		i++;
	}
	i = 0;
	while (i < rtv1->c_edits)
	{
		SDL_BlitSurface((rtv1->active_edit == i ?
			rtv1->edits[i].with_text_active : rtv1->edits[i].with_text),
			&((SDL_Rect){-rtv1->edits[i].x, -rtv1->edits[i].y,
			rtv1->edits[i].x + 100, rtv1->edits[i].y + 30}), rtv1->ui,
			NULL);
		i++;
	}
}
