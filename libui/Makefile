# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chorange <chorange@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 14:13:10 by dwdraugr          #+#    #+#              #
#    Updated: 2019/06/29 13:23:07 by chorange         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libui.a

FLAGS = -Wextra -Wall -Werror

OBJECTS  = libui_button.o libui_DropList.o libui_Edit.o libui_Disactive.o\
			libui_KeyInput.o libui_GetWithFunction.o

INCLUDES = -I./frameworks/SDL2.framework/Headers

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS) 

$(OBJECTS): %.o: %.c
	gcc -c $(FLAGS) $(INCLUDES) $< -o $@

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
