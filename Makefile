# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/15 08:55:39 by atahiri           #+#    #+#              #
#    Updated: 2020/03/09 21:39:25 by atahiri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = cub3d.a
AR = ar
FLAGS = -Wall -Werror -Wextra
SRC = *.c

all:$(NAME)

$(NAME):
	$(CC) $(FLAGS) -o Cub3d -l mlx -framework OpenGL -framework AppKit $(SRC) -fsanitize=address -Ofast
clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
re:fclean all