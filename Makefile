# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snicolet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/28 16:24:25 by snicolet          #+#    #+#              #
#*   Updated: 2016/01/04 12:55:03 by snicolet         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

CC=clang
FLAGS=-Wall -Werror -Wextra -Weverything
LIBFT=../libft
MLX=./minilibx
MLXFRAMEWORK=-framework OpenGL -framework AppKit
MLXFLAGS=-lmlx -L$(MLX) $(MLXFRAMEWORK)
DRAW_PATH=./draw/

OBJ=main.o
NAME=fdf

all: $(NAME)

lis:
	make -C $(LIBFT) EXTRA_FLAGS= BTREE=
	make -C $(DRAW_PATH) FLAGS="$(FLAGS)"

prename: $(OBJ)

$(NAME): $(OBJ) lis
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)  -L $(LIBFT) -lft $(MLXFLAGS) -L $(DRAW_PATH) -ldraw -I $(DRAW_PATH)

%.o: %.c
	$(CC) -c $< $(FLAGS) -I $(MLX) -I $(LIBFT) -I. -I $(DRAW_PATH)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C $(DRAW_PATH) fclean
	make -C $(LIBFT) fclean
draw:
	make -C $(DRAW_PATH)

re: fclean all

.PHONY: clean fclean re draw
