/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_math2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 12:00:58 by chorange          #+#    #+#             */
/*   Updated: 2019/07/08 21:28:56 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		vector_length(t_vector a)
{
	double	result;

	result = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
	return (result);
}

t_vector	vector_init(double x, double y, double z)
{
	t_vector	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

t_vector	vector_project(t_vector a, t_vector b)
{
	t_vector	project;
	double		dot;

	dot = scal_mult(a, b) / scal_mult(b, b);
	project = vector_int_mult(b, dot);
	return (project);
}

t_vector	vector_normalize(t_vector a)
{
	t_vector	c;

	c = vector_int_div(a, sqrt(scal_mult(a, a)));
	return (c);
}

t_vector	vector_cross(t_vector a, t_vector b)
{
	t_vector	r;

	r.x = a.y * b.z - a.z * b.y;
	r.y = a.z * b.x - a.x * b.z;
	r.z = a.x * b.y - a.y * b.x;
	return (r);
}

/*
** double A = cos(angles.x);	arr[0];
** double B = sin(angles.x);	arr[1];
** double C = cos(angles.y);	arr[2];
** double D = sin(angles.y);	arr[3];
** double E = cos(angles.z);	arr[4];
** double F = sin(angles.z);	arr[5];
**
** double AD = A * D;			arr[6];
** double BD = B * D;			arr[7];
*/
void		rot_help(t_vector angles, double *arr)
{
	arr[0] = cos(angles.x);
	arr[1] = sin(angles.x);
	arr[2] = cos(angles.y);
	arr[3] = sin(angles.y);
	arr[4] = cos(angles.z);
	arr[5] = sin(angles.z);
	arr[6] = arr[0] * arr[3];
	arr[7] = arr[1] * arr[3];
}

t_vector	rot(t_vector P, t_vector angles)
{
	t_vector	ret;
	double		mat[16];
	double		arr[8];

	rot_help(angles, arr);
    mat[0] =   arr[2] * arr[4];
    mat[1] =  -arr[2] * arr[5];
    mat[2] =  -arr[3];
    mat[4] = -arr[7] * arr[4] + arr[0] * arr[5];
    mat[5] =  arr[7] * arr[5] + arr[0] * arr[4];
    mat[6] =  -arr[1] * arr[2];
    mat[8] =  arr[6] * arr[4] + arr[1] * arr[5];
    mat[9] = -arr[6] * arr[5] + arr[1] * arr[4];
    mat[10]=   arr[0] * arr[2];
    mat[3] =  mat[7] = mat[11] = mat[12] = mat[13] = mat[14] = 0.0;
    mat[15]=  1.0;
	ret.x = P.x * mat[0] + P.y * mat[1] + P.z * mat[2];
	ret.y = P.x * mat[4] + P.y * mat[5] + P.z * mat[6];
	ret.z = P.x * mat[8] + P.y * mat[9] + P.z * mat[10];
	return (ret);
}
