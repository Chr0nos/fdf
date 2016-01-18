# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snicolet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/28 16:24:25 by snicolet          #+#    #+#              #
#*   Updated: 2016/01/12 11:45:25 by snicolet         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

CC=clang
FLAGS=-Wall -Werror -Wextra -Weverything
LIBFT=./libs/libft
DRAW_PATH=./libs/draw/
MLX=../minilibx
MLX_FLAGS_LINUX=-lXext -lX11 -lm -L ./libs/minilibx
MLX_FLAGS_MAC=-lm -framework OpenGL -framework AppKit -L ./libs/minilibx_macos
MLX_FLAGS=$(MLX_FLAGS_LINUX)
LIBS=-L$(DRAW_PATH) -ldraw -L$(LIBFT) -lft $(MLX_FLAGS) -lmlx
INCLUDES=-I$(LIBFT) -I$(DRAW_PATH) -I.

OBJ=main.o reader.o
NAME=fdf

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT) EXTRA_FLAGS= BTREE=
	make -C $(DRAW_PATH) FLAGS="$(FLAGS)" LIBFT=../libft/ MLX=$(MLX)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBS)

%.o: %.c
	$(CC) -c $< $(FLAGS) $(INCLUDES)

clean:
	$(RM) $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C $(DRAW_PATH) fclean
	make -C $(LIBFT) fclean
draw:
	make -C $(DRAW_PATH)

re: fclean all

.PHONY: clean fclean re draw
