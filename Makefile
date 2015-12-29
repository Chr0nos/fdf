# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snicolet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/28 16:24:25 by snicolet          #+#    #+#              #
#    Updated: 2015/12/29 13:42:02 by snicolet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=clang
FLAGS=-Wall -Werror -Wextra -Weverything -fsanitize=address
MLX=./minilibx_macos
MLXFLAGS=-lmlx -framework OpenGL -framework AppKit
LIBFT=../libft/
DRAW_PATH=./draw/

OBJ=main.o \
	aera.o
NAME=fdf

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(DRAW_PATH) FLAGS="$(FLAGS)"
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)  -L $(LIBFT) -lft $(MLXFLAGS) -L $(DRAW_PATH) -ldraw -I $(DRAW_PATH)

%.o: %.c
	$(CC) -c $< $(FLAGS) -I $(MLX) -I $(LIBFT) -I. -I $(DRAW_PATH)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C $(DRAW_PATH) fclean

re: fclean all

.PHONY: clean fclean re draw
