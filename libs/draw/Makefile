# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snicolet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/29 12:33:23 by snicolet          #+#    #+#              #
#*   Updated: 2016/01/12 11:41:54 by snicolet         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

CC=clang
FLAGS=-Wall -Wextra -Weverything
LIBFT=../libft/
MLX=../minilibx_macos
NAME=libdraw.a
OBJ=draw_line.o \
	draw_rect.o draw_rect_fill.o draw_rect_mist.o \
	draw_circle.o \
	draw_px.o draw_get_px.o \
	draw_new_image.o \
	draw_init.o \
	draw_flush_image.o \
	draw_make_line.o \
	draw_make_rect.o \
	draw_make_circle.o \
	draw_make_px.o \
	draw_putpoint.o \
	draw_reset_image.o \
	draw_loop.o \
	draw_clear.o \
	draw_perimeter.o \
	draw_sethook.o

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(MLX)
	$(AR) rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ) $(MLXOBJ)

fclean: clean
	rm -f $(NAME)
	make -C $(MLX) clean
	rm -f $(MLX)/libmlx.a

re: fclean all

%.o: %.c
	$(CC) -c $< $(FLAGS) -I $(MLX) -I $(LIBFT) -I../

.PHONY: re fclean clean
