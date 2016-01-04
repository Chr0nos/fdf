# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snicolet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/29 12:33:23 by snicolet          #+#    #+#              #
#*   Updated: 2016/01/04 22:15:50 by snicolet         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

CC=clang
FLAGS=-Wall -Wextra -Weverything
LIBFT=../../libft/
MLX=./minilibx
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
	draw_putpoint.o \
	draw_reset_image.o \
	draw_loop.o \
	draw_clear.o

MLXOBJ=mlx_init.o \
	   mlx_new_window.o \
	   mlx_pixel_put.o \
	   mlx_loop.o \
	   mlx_mouse_hook.o \
	   mlx_key_hook.o mlx_expose_hook.o mlx_loop_hook.o \
	   mlx_int_anti_resize_win.o mlx_int_do_nothing.o \
	   mlx_int_wait_first_expose.o mlx_int_get_visual.o \
	   mlx_flush_event.o mlx_string_put.o mlx_new_image.o \
	   mlx_get_data_addr.o mlx_put_image_to_window.o \
	   mlx_get_color_value.o mlx_clear_window.o mlx_xpm.o \
	   mlx_int_str_to_wordtab.o mlx_destroy_window.o mlx_int_param_event.o \
	   mlx_int_set_win_event_mask.o mlx_hook.o mlx_rgb.o mlx_destroy_image.o

all: $(NAME)

$(NAME): $(OBJ)
	@echo -e "\033[32mBuilding Minilibx\033[0m"
	@make -C $(MLX)
	@echo -e "\033[32mUnpacking MLX\033[0m"
	ar xo $(MLX)/libmlx.a
	$(AR) rc $(NAME) $(OBJ) $(MLXOBJ)
	$(AR) qs $(NAME) $(LIBFT)/libft.a
	rm -f $(MLXOBJ)
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
