/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 12:58:18 by chorange          #+#    #+#             */
/*   Updated: 2019/07/12 18:12:46 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		read_obj_parameters_1(char *line, t_obj **obj)
{
	if (ft_strstr(line, "rotate"))
		(*obj)->rot = (read_vector(ft_strchr(line, '=') + 1));
	else if (ft_strstr(line, "specular"))
		(*obj)->specular = ft_atof(ft_strchr(line, '=') + 1);
	else if (ft_strstr(line, "reflective"))
		(*obj)->reflective = ft_atof(ft_strchr(line, '=') + 1);
	else if (ft_strstr(line, "refractive"))
		(*obj)->refractive = ft_atof(ft_strchr(line, '=') + 1);
	else if (ft_strstr(line, "smoothness"))
		(*obj)->smoothness = ft_atof(ft_strchr(line, '=') + 1);
	else if (ft_strstr(line, "transparency"))
		(*obj)->transparency = ft_atof(ft_strchr(line, '=') + 1);
	else if (ft_strstr(line, "texture-id"))
		(*obj)->tex = ft_atoi(ft_strchr(line, '=') + 1);
}

t_obj		*read_obj_parameters(char *line, t_obj **obj)
{
	if (ft_strchr(line, '}'))
		return (NULL);
	else if (ft_strstr(line, "type"))
		set_obj_type(line, *obj);
	else if (ft_strstr(line, "position"))
		(*obj)->center = read_vector(ft_strchr(line, '=') + 1);
	else if (ft_strstr(line, "pos2"))
		(*obj)->p2 = read_vector(ft_strchr(line, '=') + 1);
	else if (ft_strstr(line, "pos3"))
		(*obj)->p3 = read_vector(ft_strchr(line, '=') + 1);
	else if (ft_strstr(line, "radius"))
		(*obj)->radius = ft_atof(ft_strchr(line, '=') + 1);
	else if (ft_strstr(line, "color"))
		(*obj)->rgb = color_to_rgb(ft_atoi(ft_strchr(line, '=') + 1));
	else if (ft_strstr(line, "angle"))
		(*obj)->angle = ft_atof(ft_strchr(line, '=') + 1);
	else if (ft_strstr(line, "direction"))
		(*obj)->dir = vector_normalize(read_vector(ft_strchr(line, '=') + 1));
	else
		read_obj_parameters_1(line, obj);
	return (*obj);
}
