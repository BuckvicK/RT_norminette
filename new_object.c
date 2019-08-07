/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 19:25:19 by cocummin          #+#    #+#             */
/*   Updated: 2019/07/31 14:18:22 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** int		id;		arr[0];
** int		i;		arr[1];
** int		f_exit;	arr[2];
*/
int		get_free_id(t_rtv1 *rtv1)
{
	int		arr[3];

	arr[2] = 0;
	arr[1] = 0;
	arr[0] = rand() % 200;
	while (rtv1->scene.c_objs)
	{
		arr[1] = 0;
		while (arr[1] < rtv1->scene.c_objs)
		{
			if (rtv1->scene.objs[arr[1]].id == arr[0])
				break;
			
			arr[1]++;
			if (arr[1] == rtv1->scene.c_objs)
				arr[2] = 1;
		}
		if (arr[2])
			break;
		arr[0] = rand() % 200;
	}
	return (arr[0]);
}


void	new_sphere(t_rtv1 *rtv1)
{
	rtv1->scene.objs[rtv1->scene.c_objs].type = sphere;
	rtv1->scene.objs[rtv1->scene.c_objs].center = (t_vector){0.0, 0.0, 7.0};
	rtv1->scene.objs[rtv1->scene.c_objs].rot = (t_vector){0.0, 0.0, 0.0};
	rtv1->scene.objs[rtv1->scene.c_objs].radius = 1.0;
	rtv1->scene.objs[rtv1->scene.c_objs].specular = 20.0;
	rtv1->scene.objs[rtv1->scene.c_objs].rgb = (t_rgb){rand() % 255, \
		rand()%255, rand()%255};
	rtv1->scene.objs[rtv1->scene.c_objs].reflective = 0.0;
	rtv1->scene.objs[rtv1->scene.c_objs].transparency = 0.0;
	rtv1->scene.objs[rtv1->scene.c_objs].refractive = 1.0;
	rtv1->scene.objs[rtv1->scene.c_objs].tex = -1;
	rtv1->scene.objs[rtv1->scene.c_objs].id = get_free_id(rtv1);
	rtv1->scene.c_objs++;
}

void	new_cone(t_rtv1 *rtv1)
{
	rtv1->scene.objs[rtv1->scene.c_objs].type = cone;
	rtv1->scene.objs[rtv1->scene.c_objs].center = (t_vector){0.0, 0.0, 7.0};
	rtv1->scene.objs[rtv1->scene.c_objs].dir = (t_vector){0.0, 1.0, 0.0};
	rtv1->scene.objs[rtv1->scene.c_objs].rot = (t_vector){0.0, 0.0, 0.0};
	rtv1->scene.objs[rtv1->scene.c_objs].rgb = (t_rgb){rand() % 255, \
		rand()%255, rand()%255};
	rtv1->scene.objs[rtv1->scene.c_objs].angle = 0.2;
	rtv1->scene.objs[rtv1->scene.c_objs].specular = 20.0;
	rtv1->scene.objs[rtv1->scene.c_objs].reflective = 0.0;
	rtv1->scene.objs[rtv1->scene.c_objs].transparency = 0.0;
	rtv1->scene.objs[rtv1->scene.c_objs].refractive = 1.0;
	rtv1->scene.objs[rtv1->scene.c_objs].tex = -1;
	rtv1->scene.objs[rtv1->scene.c_objs].id = get_free_id(rtv1);
	rtv1->scene.c_objs++;
}

void	new_cylinder(t_rtv1 *rtv1)
{
	rtv1->scene.objs[rtv1->scene.c_objs].type = cylinder;
	rtv1->scene.objs[rtv1->scene.c_objs].center = (t_vector){0.0, 0.0, 7.0};
	rtv1->scene.objs[rtv1->scene.c_objs].dir = (t_vector){0.0, 1.0, 0.0};
	rtv1->scene.objs[rtv1->scene.c_objs].rot = (t_vector){0.0, 0.0, 0.0};
	rtv1->scene.objs[rtv1->scene.c_objs].radius = 1.0;
	rtv1->scene.objs[rtv1->scene.c_objs].rgb = (t_rgb){rand() % 255, \
		rand()%255, rand()%255};
	rtv1->scene.objs[rtv1->scene.c_objs].specular = 20.0;
	rtv1->scene.objs[rtv1->scene.c_objs].reflective = 0.0;
	rtv1->scene.objs[rtv1->scene.c_objs].refractive = 1.0;
	rtv1->scene.objs[rtv1->scene.c_objs].tex = -1;
	rtv1->scene.objs[rtv1->scene.c_objs].id = get_free_id(rtv1);
	rtv1->scene.c_objs++;
}

void	new_plane(t_rtv1 *rtv1)
{
	rtv1->scene.objs[rtv1->scene.c_objs].type = plane;
	rtv1->scene.objs[rtv1->scene.c_objs].center = (t_vector){0.0, 0.0, 7.0};
	rtv1->scene.objs[rtv1->scene.c_objs].dir = (t_vector){0.0, 1.0, 0.0};
	rtv1->scene.objs[rtv1->scene.c_objs].rot = (t_vector){0.0, 0.0, 0.0};
	rtv1->scene.objs[rtv1->scene.c_objs].rgb = (t_rgb){rand() % 255, \
		rand()%255, rand()%255};
	rtv1->scene.objs[rtv1->scene.c_objs].specular = 20.0;
	rtv1->scene.objs[rtv1->scene.c_objs].transparency = 0.0;
	rtv1->scene.objs[rtv1->scene.c_objs].refractive = 1.0;
	rtv1->scene.objs[rtv1->scene.c_objs].reflective = 0.0;
	rtv1->scene.objs[rtv1->scene.c_objs].tex = -1;
	rtv1->scene.objs[rtv1->scene.c_objs].id = get_free_id(rtv1);
	rtv1->scene.c_objs++;
}
