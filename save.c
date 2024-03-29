/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 19:25:19 by cocummin          #+#    #+#             */
/*   Updated: 2019/07/31 14:18:22 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		save_with_defense(char *file_name)
{
	int		fd;
	char	*str;
	char	*key;
	int		len;

	fd = open(file_name, O_RDONLY);
	str = (char *)malloc(300000);
	len = read(fd, str, 300000);
	str[len] = 0;
	key = get_crypto_key(str);
	close(fd);
	fd = open(file_name, O_TRUNC | O_RDWR | O_CREAT,
		S_IRWXU | S_IRWXG | S_IRWXO);
	ft_putendl_fd(key, fd);
	ft_putstr_fd(str, fd);
	close(fd);
	free(key);
	free(str);
}

void		save_cam(t_rtv1 *rtv1, int fd)
{
	char	*tmp;

	ft_putstr_fd("camera_init\n{\n\tposition = (", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.camera.center.x), fd);
	free(tmp);
	ft_putstr_fd(", ", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.camera.center.y), fd);
	free(tmp);
	ft_putstr_fd(", ", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.camera.center.z), fd);
	free(tmp);
	ft_putstr_fd(")\n\tdirection = (", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.camera.dir.x), fd);
	free(tmp);
	ft_putstr_fd(", ", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.camera.dir.y), fd);
	free(tmp);
	ft_putstr_fd(", ", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.camera.dir.z), fd);
	free(tmp);
	ft_putstr_fd(")\n}\n\n", fd);
}

void		put_name_obj(t_rtv1 *rtv1, int fd, int i)
{
	ft_putstr_fd("new object\n{\n\ttype = ", fd);
	if (rtv1->scene.objs[i].type == sphere)
		ft_putstr_fd("sphere\n", fd);
	else if (rtv1->scene.objs[i].type == cylinder)
		ft_putstr_fd("cylinder\n", fd);
	else if (rtv1->scene.objs[i].type == cone)
		ft_putstr_fd("cone\n", fd);
	else if (rtv1->scene.objs[i].type == plane)
		ft_putstr_fd("plane\n", fd);
	else if (rtv1->scene.objs[i].type == paraboloid)
		ft_putstr_fd("paraboloid\n", fd);
	else if (rtv1->scene.objs[i].type == triangle)
		ft_putstr_fd("triangle\n", fd);
}

void		put_position(t_rtv1 *rtv1, int fd, int i)
{
	char	*tmp;

	ft_putstr_fd("\tposition = (", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.objs[i].center.x), fd);
	free(tmp);
	ft_putstr_fd(", ", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.objs[i].center.y), fd);
	free(tmp);
	ft_putstr_fd(", ", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.objs[i].center.z), fd);
	free(tmp);
}

void		put_position_2(t_rtv1 *rtv1, int fd, int i)
{
	char	*tmp;

	ft_putstr_fd(")\n\tpos2 = (", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.objs[i].p2.x), fd);
	free(tmp);
	ft_putstr_fd(", ", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.objs[i].p2.y), fd);
	free(tmp);
	ft_putstr_fd(", ", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.objs[i].p2.z), fd);
	free(tmp);
}

void		put_position_3(t_rtv1 *rtv1, int fd, int i)
{
	char	*tmp;

	ft_putstr_fd(")\n\tpos3 = (", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.objs[i].p3.x), fd);
	free(tmp);
	ft_putstr_fd(", ", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.objs[i].p3.y), fd);
	free(tmp);
	ft_putstr_fd(", ", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.objs[i].p3.z), fd);
	free(tmp);
}

void		put_something_1(t_rtv1 *rtv1, int fd, int i)
{
	char	*tmp;

	ft_putstr_fd(")\n\tdirection = (", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.objs[i].dir.x), fd);
	free(tmp);
	ft_putstr_fd(", ", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.objs[i].dir.y), fd);
	free(tmp);
	ft_putstr_fd(", ", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.objs[i].dir.z), fd);
	free(tmp);
	ft_putstr_fd(")\n\trotate = (", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.objs[i].rot.x), fd);
	free(tmp);
	ft_putstr_fd(", ", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.objs[i].rot.y), fd);
	free(tmp);
	ft_putstr_fd(", ", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.objs[i].rot.z), fd);
	free(tmp);
}

void		put_something_2(t_rtv1 *rtv1, int fd, int i)
{
	char	*tmp;

	ft_putstr_fd(")\n\tradius = ", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.objs[i].radius), fd);
	free(tmp);
	ft_putstr_fd("\n\tcolor = ", fd);
	ft_putstr_fd(tmp = ft_itoa(rgb_to_color(rtv1->scene.objs[i].rgb)), fd);
	free(tmp);
	ft_putstr_fd("\n\tspecular = ", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.objs[i].specular), fd);
	free(tmp);
	ft_putstr_fd("\n\treflective = ", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.objs[i].reflective), fd);
	free(tmp);
	ft_putstr_fd("\n\trefractive = ", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.objs[i].refractive), fd);
	free(tmp);
	ft_putstr_fd("\n\ttransparency = ", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.objs[i].transparency), fd);
	free(tmp);
}

void		put_something_3(t_rtv1 *rtv1, int fd, int i)
{
	char	*tmp;

	ft_putstr_fd("\n\tsmoothness = ", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.objs[i].smoothness), fd);
	free(tmp);
	ft_putstr_fd("\n\tangle = ", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.objs[i].angle), fd);
	free(tmp);
	ft_putstr_fd("\n\ttexture-id = ", fd);
	ft_putstr_fd(tmp = ft_itoa(rtv1->scene.objs[i].tex), fd);
	free(tmp);
	ft_putstr_fd("\n}\n\n", fd);
}

void		put_objs(t_rtv1 *rtv1, int fd, int i)
{
	put_name_obj(rtv1, fd, i);
	put_position(rtv1, fd, i);
	put_position_2(rtv1, fd, i);
	put_position_3(rtv1, fd, i);
	put_something_1(rtv1, fd, i);
	put_something_2(rtv1, fd, i);
	put_something_3(rtv1, fd, i);
}

void		put_light_1(t_rtv1 *rtv1, int fd, int i)
{
	ft_putstr_fd("new light\n{\n\ttype = ", fd);
	if (rtv1->scene.lights[i].type == point)
		ft_putstr_fd("point\n", fd);
	else if (rtv1->scene.lights[i].type == ambient)
		ft_putstr_fd("ambient\n", fd);
	else if (rtv1->scene.lights[i].type == directional)
		ft_putstr_fd("directional\n", fd);
}

void		put_light_2(t_rtv1 *rtv1, int fd, int i)
{
	char	*tmp;

	ft_putstr_fd("\tintensity = ", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.lights[i].intensity), fd);
	free(tmp);
	ft_putstr_fd("\n\tposition = (", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.lights[i].center.x), fd);
	free(tmp);
	ft_putstr_fd(", ", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.lights[i].center.y), fd);
	free(tmp);
	ft_putstr_fd(", ", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.lights[i].center.z), fd);
	free(tmp);
	ft_putstr_fd(")\n\tdirection = (", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.lights[i].dir.x), fd);
	free(tmp);
	ft_putstr_fd(", ", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.lights[i].dir.y), fd);
	free(tmp);
	ft_putstr_fd(", ", fd);
	ft_putstr_fd(tmp = ft_ftoa(rtv1->scene.lights[i].dir.z), fd);
	free(tmp);
	ft_putstr_fd(")\n}\n", fd);
}

void		save(t_rtv1 *rtv1, char *filename)
{
	int		fd;
	char	*tmp;
	int		i;

	fd = open(filename, O_TRUNC | O_RDWR | O_CREAT,
		S_IRWXU | S_IRWXG | S_IRWXO);
	save_cam(rtv1, fd);
	i = 0;
	while (i < rtv1->scene.c_objs)
	{
		put_objs(rtv1, fd, i);
		i++;
	}
	i = 0;
	while (i < rtv1->scene.c_lights)
	{
		put_light_1(rtv1, fd, i);
		put_light_2(rtv1, fd, i);
		i++;
	}
	ft_putstr_fd("\n\nend", fd);
	close(fd);
	save_with_defense(filename);
}

void		save_as(t_rtv1 *rtv1)
{
	char	full_name[256];
	char	base_name[64];

	ft_strcpy(base_name, \
		rtv1->edits[libui_geteditwithfunction(rtv1->edits, \
		rtv1->c_edits, "Name")].text);
	if (ft_strlen(base_name))
	{
		ft_strcpy(full_name, "scenes/");
		ft_strcat(full_name, base_name);
		save(rtv1, full_name);
		ft_strcpy(rtv1->scene_file_name, full_name);
	}
}
