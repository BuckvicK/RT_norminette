/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 10:55:19 by chorange          #+#    #+#             */
/*   Updated: 2019/07/13 19:43:12 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector		read_vector(char *str)
{
	t_vector	ret;

	while (*str == ' ' || *str == '\t' || *str == '(')
		str++;
	ret.x = ft_atof(str);
	str = ft_strchr(str, ',') + 1;
	ret.y = ft_atof(str);
	str = ft_strchr(str, ',') + 1;
	ret.z = ft_atof(str);
	return (ret);
}

static void		new_object(t_scene *scene, t_obj **obj, int *i)
{
	*i = (*i) + 1;
	*obj = &(scene->objs[*i]);
	(*obj)->id = *i;

}

static void		new_light(t_scene *scene, t_light **light, int *j)
{
	*j = (*j) + 1;
	*light = &(scene->lights[*j]);
	(*light)->id = *j;
}

void			read_line_set_scene(char *line, t_scene *scene)
{
	static int			i = -1;
	static int			j = -1;
	static t_obj		*obj = NULL;
	static t_light		*light = NULL;
	static t_camera		*camera = NULL;

	if (ft_strstr(line, "camera_init"))
		camera = camera_init(line, &(scene->camera));
	if (obj)
		obj = read_obj_parameters(line, &obj);
	else if (light)
		light = read_light_parameters(line, &light);
	else if (camera)
		camera = camera_init(line, camera);
	else if (ft_strstr(line, "new") && ft_strstr(line, "object"))
		new_object(scene, &obj, &i);
	else if (ft_strstr(line, "new") && ft_strstr(line, "light"))
		new_light(scene, &light, &j);
	else if (!ft_strcmp(line, "end"))
	{
		scene->c_objs = i + 1;
		scene->c_lights = j + 1;
	}
}

void			read_file_to_line(int fd, char **ret)
{
	char *line;

	*ret = (char *)malloc(300000);
	(*ret)[0] = 0;
	while (get_next_line(fd, &line) > 0)
	{
		ft_strcat(*ret, line);
		ft_strcat(*ret, "\n");
		free(line);
	}
	(*ret)[ft_strlen(*ret) - 1] = 0;
}

int				check_crypto_key(char *file_name)
{
	char	*key;
	char	*key_from_file;
	char	*str;
	int		ret;
	int		fd;

	if ((fd = open(file_name, O_RDONLY)) < 0)
		err_exit();
	get_next_line(fd, &key_from_file);
	read_file_to_line(fd, &str);
	key = get_crypto_key(str);
	ret = ft_strcmp(key, key_from_file);
	free(key);
	free(key_from_file);
	free(str);
	close(fd);
	return (ret);
}

void			read_scene(t_scene *scene, char *file_name)
{
	int		ret;
	int		fd;
	char	*line;

	if ((fd = open(file_name, O_RDONLY)) < 0)
		err_exit();
	get_next_line(fd, &line);
	free(line);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		read_line_set_scene(line, scene);
		if (line)
			free(line);
		line = NULL;
	}
	if (ret == -1)
	{
		if (line)
			free(line);
		err_exit();
	}
	if (line)
		free(line);
	close(fd);
}
