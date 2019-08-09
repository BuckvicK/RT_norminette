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

void		ray_intersect_paraboloid_2(t_vector start, t_vector dir, t_obj *parab)
{
	double	arr[3];

	// q.a = 2.f * (scal_mult(dir, dir) - arr[0] * arr[0]);
	// q.b = 2.f * (scal_mult(dir, x) - arr[0] * (arr[1] + 2.f *  parab->radius));
	// q.c = scal_mult(x, x) - arr[1] * (arr[1] + 4.f *  parab->radius);
}

/*
** double		u;				arr[0]
** double		z;				arr[1]
** double		len;			arr[2]
** double		zero_threshold;	arr[3]
*/
double		ray_intersect_paraboloid(t_vector start, t_vector dir,
				t_obj *parab)
{
	t_s			q;
	t_vector	x;
	t_vector	hitpoint;
	double		arr[4];

	arr[3] = 0.0001;
	x = vector_subt(start, parab->center);
	arr[0] = scal_mult(dir, parab->dir);
	arr[1] = scal_mult(x, parab->dir);
	q.a = 2.f * (scal_mult(dir, dir) - arr[0] * arr[0]);
	q.b = 2.f * (scal_mult(dir, x) - arr[0] * (arr[1] + 2.f *  parab->radius));
	q.c = scal_mult(x, x) - arr[1] * (arr[1] + 4.f *  parab->radius);
	if ((q.diskr = q.b * q.b - 2.f * q.a * q.c) >= 0.f)
	{
		q = (t_s){.sq_diskr = sqrt(q.diskr), .t = (-q.b - q.sq_diskr) / q.a};
		if (q.t > 0.f)
		{
			hitpoint = vector_sum(vector_int_mult(dir, q.t), x);
			arr[2] = scal_mult(hitpoint, parab->dir);
			if (arr[2] < parab->angle && arr[2] > -arr[3])
				return (q.t);
		}
		q.t = (-q.b + q.sq_diskr) / q.a;
		if (q.t > -arr[3])
		{
			hitpoint = vector_sum(vector_int_mult(dir, q.t), x);
			arr[2] = scal_mult(hitpoint, parab->dir);
			if (arr[2] < parab->angle && arr[2] > -arr[3])
				return (q.t);
		}
	}
	return (0);
}
