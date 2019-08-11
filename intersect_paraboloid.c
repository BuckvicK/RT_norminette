/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_paraboloid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 10:41:13 by chorange          #+#    #+#             */
/*   Updated: 2019/07/08 21:30:16 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_s			q_init(t_vector dir, t_obj *parab, double *arr, t_vector *vec)
{
	t_s		q;

	arr[3] = 0.0001;
	vec[0] = vector_subt(vec[3], parab->center);
	vec[2] = dir;
	arr[0] = scal_mult(dir, parab->dir);
	arr[1] = scal_mult(vec[0], parab->dir);
	q.a = 2.f * (scal_mult(dir, dir) - arr[0] * arr[0]);
	q.b = 2.f * (scal_mult(dir, vec[0]) - arr[0] *
		(arr[1] + 2.f * parab->radius));
	q.c = scal_mult(vec[0], vec[0]) - arr[1] *
		(arr[1] + 4.f * parab->radius);
	return (q);
}

double		norm(t_s *q, t_vector *vec, double *arr, t_obj *parab)
{
	q->sq_diskr = sqrt(q->diskr);
	q->t = (-q->b - q->sq_diskr) / q->a;
	if (q->t > 0.f)
	{
		vec[1] = vector_sum(vector_int_mult(vec[2], q->t), vec[0]);
		arr[2] = scal_mult(vec[1], parab->dir);
		if (arr[2] < parab->angle && arr[2] > -arr[3])
			return (q->t);
	}
	q->t = (-q->b + q->sq_diskr) / q->a;
	if (q->t > -arr[3])
	{
		vec[1] = vector_sum(vector_int_mult(vec[2], q->t), vec[0]);
		arr[2] = scal_mult(vec[1], parab->dir);
		if (arr[2] < parab->angle && arr[2] > -arr[3])
			return (q->t);
	}
	return (0);
}

/*
** double		u;				arr[0]
** double		z;				arr[1]
** double		len;			arr[2]
** double		zero_threshold;	arr[3]
** t_vector		x;				vec[0]
** t_vector		hitpoint;		vec[1]
** t_vector		dir;			vec[2]
** t_vector		start;			vec[3]
*/
double		ray_intersect_paraboloid(t_vector start, t_vector dir,
				t_obj *parab)
{
	t_s			q;
	t_vector	vec[4];
	double		arr[4];

	vec[3] = start;
	q = q_init(dir, parab, arr, vec);
	if ((q.diskr = q.b * q.b - 2.f * q.a * q.c) >= 0.f)
	{
		return (norm(&q, vec, arr, parab));
	}
	return (0);
}
