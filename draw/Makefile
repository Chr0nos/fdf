# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snicolet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/29 12:33:23 by snicolet          #+#    #+#              #
#    Updated: 2015/12/31 13:36:32 by snicolet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=clang
FLAGS=-Wall -Wextra -Weverything -fsanitize=address
LIBFT=../../libft/
MLXFLAGS=-lmlx -framework OpenGL -framework AppKit
MLX=../minilibx_macos
NAME=libdraw.a
OBJ=draw_line.o \
	draw_box.o \
	draw_rect.o \
	draw_px.o \
	draw_new_image.o \
	draw_init.o \
	draw_flush_image.o \
	draw_make_line.o \
	draw_putpoint.o

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	$(CC) -c $< $(FLAGS) -I $(MLX) -I $(LIBFT) -I../

.PHONY: re fclean clean
