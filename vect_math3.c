/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_math3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 12:00:58 by chorange          #+#    #+#             */
/*   Updated: 2019/07/08 21:28:56 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** double A = cos(angles.x); arr[0];
** double B = sin(angles.x); arr[1];
** double C = cos(angles.y); arr[2];
** double D = sin(angles.y); arr[3];
** double E = cos(angles.z); arr[4];
** double F = sin(angles.z); arr[5];
** double AD = A * D; arr[6]
** double BD = B * D; arr[7]
*/
void		rot_init_params(double *arr, t_vector angles)
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

/*
** mat[0] =   C * E;
** mat[1] =  -C * F;
** mat[2] =  -D;
** mat[4] = -BD * E + A * F;
** mat[5] =  BD * F + A * E;
** mat[6] =  -B * C;
** mat[8] =  AD * E + B * F;
** mat[9] = -AD * F + B * E;
** mat[10]=   A * C;
** mat[3] =  mat[7] = mat[11] = mat[12] = mat[13] = mat[14] = 0.0;
** mat[15]=  1.0;
*/
void		rot_calculate_params(double *arr, double *mat)
{
	mat[0] = arr[2] * arr[4];
	mat[1] = -arr[2] * arr[5];
	mat[2] = -arr[3];
	mat[4] = -arr[7] * arr[4] + arr[0] * arr[5];
	mat[5] = arr[7] * arr[5] + arr[0] * arr[4];
	mat[6] = -arr[1] * arr[2];
	mat[8] = arr[6] * arr[4] + arr[1] * arr[5];
	mat[9] = -arr[6] * arr[5] + arr[1] * arr[4];
	mat[10] = arr[0] * arr[2];
	mat[3] = 0.0;
	mat[7] = 0.0;
	mat[11] = 0.0;
	mat[12] = 0.0;
	mat[13] = 0.0;
	mat[14] = 0.0;
	mat[15] = 1.0;
}

t_vector rot(t_vector P, t_vector angles)
{
	double		mat[16];
	double		arr[8];
	t_vector	ret;

	rot_init_params(arr, angles);
	rot_calculate_params(arr, mat);
	ret.x = P.x * mat[0] + P.y * mat[1] + P.z * mat[2];
	ret.y = P.x * mat[4] + P.y * mat[5] + P.z * mat[6];
	ret.z = P.x * mat[8] + P.y * mat[9] + P.z * mat[10];
	return (ret);
}
