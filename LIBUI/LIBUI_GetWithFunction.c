/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIBUI_GetWithFunction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 11:16:04 by chorange          #+#    #+#             */
/*   Updated: 2019/06/29 14:03:04 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBUI.h"

int		LIBUI_GetButtonWithFunction(t_LIBUI_Button *buttons, int c_buttons,
								char *function)
{
	int		i;

	i = 0;
	while (i < c_buttons)
	{
		if (!ft_strcmp(buttons[i].function, function))
			return (i);
		i++;
	}
	return (-1);
}

int		LIBUI_GetListWithFunction(t_LIBUI_List *lists, int c_lists,
								char *function)
{
	int		i;

	i = 0;
	while (i < c_lists)
	{
		if (!ft_strcmp(lists[i].items[0].function, function))
			return (i);
		i++;
	}
	return (-1);
}

int		LIBUI_GetEditWithFunction(t_LIBUI_Edit *edits, int c_edits,
								char *function)
{
	int		i;

	i = 0;
	while (i < c_edits)
	{
		if (!ft_strcmp(edits[i].function, function))
			return (i);
		i++;
	}
	return (-1);
}
