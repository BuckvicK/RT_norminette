/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui_disactiveall.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 12:07:10 by chorange          #+#    #+#             */
/*   Updated: 2019/06/29 12:14:29 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	libui_disactiveall(t_libui_edit *edits, int c_edits,
							t_libui_list *lists, int c_lists)
{
	int		i;

	i = 0;
	while (i < c_edits)
	{
		edits[i].is_active = 0;
		i++;
	}
	i = 0;
	while (i < c_lists)
	{
		lists[i].is_dropped = 0;
		i++;
	}
}
