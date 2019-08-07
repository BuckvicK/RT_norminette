/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 19:25:19 by cocummin          #+#    #+#             */
/*   Updated: 2019/07/31 14:18:22 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	read_coords(char *line)
{
	t_vector	ret;
	char		*tmp;

	tmp = ft_strchr(line, ' ') + 1;
	ret.x = atof(tmp);
	tmp = ft_strchr(tmp, ' ') + 1;
	ret.y = atof(tmp);
	tmp = ft_strchr(tmp, ' ') + 1;
	ret.z = atof(tmp);
	return (ret);
}

void		get_points(t_vector *points, char *file_name)
{
	int		fd;
	int		i;
	char	*str;
	char	*line;

	i = 0;
	if ((fd = open(file_name, O_RDONLY)) < 0)
		err_exit();
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == 'v' && line[1] == ' ')
		{
			points[i] = read_coords(line);
			i++;
		}
		free(line);
	}
	close(fd);
}

t_obj		generate_polygon(char *line, t_vector *points)
{
	t_obj	ret;
	char	*tmp;
	int		number;

	tmp = ft_strchr(line, ' ') + 1;
	number = ft_atoi(tmp);
	ret.center = points[number - 1];
	tmp = ft_strchr(tmp, ' ') + 1;
	number = ft_atoi(tmp);
	ret.p2 = points[number - 1];
	tmp = ft_strchr(tmp, ' ') + 1;
	number = ft_atoi(tmp);
	ret.p3 = points[number - 1];
	ret.type = triangle;
	ret.rgb = (t_rgb){255, 0, 0};
	ret.specular = 0.0;
	ret.reflective = 0.0;
	ret.id = 999;
	ret.tex = -1;
	return (ret);
}

void		get_polygons(t_rtv1 *rtv1, t_vector *points, char *file_name)
{
	int 	fd;
	int 	i;
	char	*str;
	char	*line;

	i = 0;
	if ((fd = open(file_name, O_RDONLY)) < 0)
		err_exit();
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == 'f' && line[1] == ' ')
		{
			rtv1->scene.objs[i] = generate_polygon(line, points);
			rtv1->scene.c_objs++;
			i++;
		}
		free(line);
	}
	close(fd);
}

void		read_obj(t_rtv1 *rtv1, char *file_name)
{
	t_vector *points;

	points = (t_vector *)malloc(sizeof(t_vector) * 30000);
	rtv1->scene.camera.center = (t_vector){0.0, 1.0, -3.0};
	rtv1->scene.camera.dir = (t_vector){0.0, 0.0, 1.0};
	rtv1->scene.lights[0].type = point;
	rtv1->scene.lights[0].center = (t_vector){1.0, 1.0, -2.0};
	rtv1->scene.lights[0].intensity = 0.7;
	rtv1->scene.lights[1].type = ambient;
	rtv1->scene.lights[1].intensity = 0.3;
	rtv1->scene.c_lights = 2;
	get_points(points, file_name);
	printf("x = %f y = %f z = %f", points[2].x, points[2].y, points[2].z);
	get_polygons(rtv1, points, file_name);
}
