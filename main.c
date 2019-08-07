/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 19:25:19 by cocummin          #+#    #+#             */
/*   Updated: 2019/07/31 14:18:22 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				main(int ac, char **av)
{
	static t_rtv1	rtv1;

	if (ac < 2 || ac > 4)
	{
		ft_putendl("Argument is not valid.");
		err_exit();
	}
	if ((ac > 2 && (ft_strcmp(av[2], "obj")) &&
		(ft_strcmp(av[2], "admin"))) || ac == 2)
		if (check_crypto_key(av[1]))
		{
			ft_putendl("иди нахуй, файл поврежден");
			exit(-2);
		}
	rtv1.from_obj = 0;
	if (ac > 2 && (!ft_strcmp(av[2], "obj") || !ft_strcmp(av[2], "obj")))
		rtv1.from_obj = 1;
	scene_init(&rtv1, av[1]);
	graphics_init(&rtv1);
	set_start_angles(&(rtv1.scene));
	while (1)
		provider(&rtv1);
	return (0);
}
