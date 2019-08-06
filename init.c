/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:10:50 by chorange          #+#    #+#             */
/*   Updated: 2019/07/31 13:49:46 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		arrows_init(t_rtv1 *rtv1)
{
	rtv1->scene.arrows_on = 0;
	rtv1->scene.arrows[0].type = arrow;
	rtv1->scene.arrows[1].type = arrow;
	rtv1->scene.arrows[2].type = arrow;
	rtv1->scene.arrows[0].center = vector_init(0.0, 0.0, 6.0);
	rtv1->scene.arrows[1].center = vector_init(0.0, 0.0, 6.0);
	rtv1->scene.arrows[2].center = vector_init(0.0, 0.0, 6.0);
	rtv1->scene.arrows[0].dir = vector_init(1.0, 0.0, 0.0);
	rtv1->scene.arrows[1].dir = vector_init(0.0, 1.0, 0.0);
	rtv1->scene.arrows[2].dir = vector_init(0.0, 0.0, 1.0);
	rtv1->scene.arrows[0].rgb = (t_rgb){255, 0, 0};
	rtv1->scene.arrows[1].rgb = (t_rgb){0, 255, 0};
	rtv1->scene.arrows[2].rgb = (t_rgb){0, 0, 255};
}

void		scene_init(t_rtv1 *rtv1, char *name)
{
	ft_strcpy(rtv1->scene_file_name, name);
	arrows_init(rtv1);
	rtv1->scene.shadows_on = 1;
	if (rtv1->from_obj)
		read_obj(rtv1, rtv1->scene_file_name);
	else
		read_scene(&(rtv1->scene), rtv1->scene_file_name);
}

static void	compile_from_file_1(t_rtv1 *rtv1, size_t *l_size)
{
	char	*logg;

	logg = NULL;
	clGetProgramBuildInfo(rtv1->program, rtv1->device_id,
		CL_PROGRAM_BUILD_LOG, 0, NULL, l_size);
	logg = malloc(*l_size);
	clGetProgramBuildInfo(rtv1->program, rtv1->device_id,
		CL_PROGRAM_BUILD_LOG, *l_size, logg, NULL);
	puts(logg);
	free(logg);
}

void		compile_from_file(char *file_name, t_rtv1 *rtv1)
{
	size_t	source_size;
	char	*source_str;
	int		fd;
	size_t	l_size;

	fd = open(file_name, O_RDONLY);
	if (fd <= 0)
		err_exit();
	source_str = (char *)malloc(MAX_SOURCE_SIZE);
	source_str[read(fd, source_str, MAX_SOURCE_SIZE)] = 0;
	source_size = ft_strlen(source_str);
	close(fd);
	rtv1->program = clCreateProgramWithSource(rtv1->context, 1,
		(const char **)&source_str, (const size_t *)&source_size, &rtv1->ret);
	rtv1->ret = clBuildProgram(rtv1->program, 1, &rtv1->device_id,
		NULL, NULL, NULL);
	compile_from_file_1(rtv1, &l_size);
	free(source_str);
}
