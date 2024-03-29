/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui_KeyInput.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 12:31:28 by chorange          #+#    #+#             */
/*   Updated: 2019/06/29 13:14:39 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	libui_inputletter(int key, t_libui_edit *edits,
			int number, int shift)
{
	int		len;

	len = ft_strlen(edits[number].text);
	if (key > 32 && key < 127)
	{
		if (len < 11)
		{
			if (shift && (key >= 'a' && key <= 'z'))
				key -= 32;
			edits[number].text[len] = key;
		}
	}
	else if (key == 8 && len > 0)
		edits[number].text[len - 1] = 0;
	libui_editrefresh(edits, number);
}
