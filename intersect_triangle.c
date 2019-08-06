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
** t_vector		e1;
** t_vector		e2;
** t_vector		p;
** t_vector		vertex_camera_direction;
** t_vector		q;
*/
double ray_intersect_triangle(t_vector start, t_vector dir, t_obj *triangle)
{
	t_vector		e1;
	t_vector		e2;
	t_vector		p;
	t_vector		vertex_camera_direction;
	t_vector		q;
	double			det;
	double			u;
	double			v;
	double			intersection;

	e1 = vector_subt(triangle->p2, triangle->center);
	e2 = vector_subt(triangle->p3, triangle->center);
	p = vector_cross(dir, e2);
	det = scal_mult(e1, p);
	if (det > -0.00001 && det < 0.000001)
		return (0.0);
	vertex_camera_direction = vector_subt(start, triangle->center);
	u = scal_mult(vertex_camera_direction, p) * (1 / det);
	if (u < 0 || u > 1)
		return (0.0);
	q = vector_cross(vertex_camera_direction, e1);
	v = scal_mult(dir, q) * (1 / det);
	if (v < 0 || (u + v) > 1)
		return (0.0);
	intersection = scal_mult(e2, q) * (1 / det);
	if (intersection > 0.00001)
		return (intersection);
	return (0.0);
}
