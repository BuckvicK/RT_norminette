/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   libui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorange <chorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 12:31:28 by chorange          #+#    #+#             */
/*   Updated: 2019/06/29 13:14:39 by chorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef libui_H
# define libui_H
# include "frameworks/SDL2.framework/Headers/SDL.h"
# include "frameworks/SDL2_image.framework/Headers/SDL_image.h"
# include "frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
# include "../libft/libft.h"

typedef struct		s_but_constr
{
	int				x;
	int				y;
	char			*text;
	char			*function;
	int				color;
}					t_but_constr;

typedef struct		s_edit_constr
{
	int				x;
	int				y;
	char			*text;
	char			*function;
	int				color;
}					t_edit_constr;

typedef struct		s_list_constr
{
	int				x;
	int				y;
	char			*text;
	char			*function;
	int				color;
	char			items_text[20][64];
	char			items_function[20][64];
	int				c_items;
}					t_list_constr;

typedef struct		s_libui_Button
{
	int				x;
	int				y;
	SDL_Surface		*surface;
	SDL_Surface		*pressed;
	char			function[64];
	int				is_pressed;
}					t_libui_button;

typedef struct		s_libui_Edit
{
	int				x;
	int				y;
	int				is_active;
	char			text[64];
	SDL_Surface		*surface;
	SDL_Surface		*active;
	SDL_Surface		*with_text;
	SDL_Surface		*with_text_active;
	char			function[64];
}					t_libui_Edit;

typedef struct		s_libui_List
{
	int				x;
	int				y;
	int				is_dropped;
	t_libui_button	*items;
	int				c_items;
}					t_libui_List;

typedef struct		s_list_item_addr
{
	int				list;
	int				item;
}					t_list_item_addr;

void				libui_drop_list(void *rtv1, int x, int y);
int					libui_isbuttonpressed(int x, int y,
						t_libui_button *buttons, int c_buttons);
void				libui_newbutton(t_but_constr button,
						t_libui_button *buttons, int *c_buttons);
t_libui_button		libui_createbutton(t_but_constr input);
void				libui_newlist(t_list_constr list,
						t_libui_List *lists, int *c_lists);
t_list_item_addr	libui_islistpressed(int x, int y,
						t_libui_List *lists, int c_lists);
void				libui_newedit(t_edit_constr edit,
						t_libui_Edit *edits, int *c_edits);
int					libui_iseditpressed(int x, int y,
						t_libui_Edit *edits, int c_edits);
void				libui_editrefresh(t_libui_Edit *edits, int number);
void				libui_disactiveall(t_libui_Edit *edits, int c_edits,
						t_libui_List *lists, int c_lists);
void				libui_inputletter(int key, t_libui_Edit *edits,
						int number, int shift);
int					libui_getbuttonwithfunction(t_libui_button *buttons,
						int c_buttons, char *function);
int					libui_getlistwithfunction(t_libui_List *lists,
						int c_lists, char *function);
int					libui_geteditwithfunction(t_libui_Edit *edits,
						int c_edits, char *function);

#endif
