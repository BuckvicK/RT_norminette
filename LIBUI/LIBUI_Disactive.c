/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui_Disactive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 12:07:10 by chorange          #+#    #+#             */
/*   Updated: 2019/06/29 12:14:29 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void libui_DisactiveAll(t_libui_Edit *edits, int c_edits,
                        t_libui_List *lists, int c_lists)
{
    int i;

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