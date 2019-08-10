/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 10:41:13 by chorange          #+#    #+#             */
/*   Updated: 2019/07/08 21:30:16 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
**
** t_vector	e1;							vec[0]
** t_vector	e2;							vec[1]
** t_vector	p;							vec[2]
** t_vector	vertex_camera_direction;	vec[3]
** t_vector	q;							vec[4]
**
** double	det;						arr[0]
** double	u;							arr[1]
** double	v;							arr[2]
** double	intersection;				arr[3]
*/
double ray_intersect_triangle(t_vector start, t_vector dir, t_obj *triangle)
{
	t_vector	vec[5];
	double		arr[4];

	vec[0] = vector_subt(triangle->p2, triangle->center);
	vec[1] = vector_subt(triangle->p3, triangle->center);
	vec[2] = vector_cross(dir, vec[1]);
	arr[0] = scal_mult(vec[0], vec[2]);
	if (arr[0] > -0.00001 && arr[0] < 0.000001)
		return (0.0);
	vec[3] = vector_subt(start, triangle->center);
	arr[1] = scal_mult(vec[3], vec[2]) * (1 / arr[0]);
	if (arr[1] < 0 || arr[1] > 1)
		return (0.0);
	vec[4] = vector_cross(vec[3], vec[0]);
	arr[2] = scal_mult(dir, vec[4]) * (1 / arr[0]);
	if (arr[2] < 0 || (arr[1] + arr[2]) > 1)
		return (0.0);
	arr[3] = scal_mult(vec[1], vec[4]) * (1 / arr[0]);
	if (arr[3] > 0.00001)
		return (arr[3]);
	return (0.0);
}
