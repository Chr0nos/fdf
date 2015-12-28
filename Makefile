# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snicolet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/28 16:24:25 by snicolet          #+#    #+#              #
#    Updated: 2015/12/28 19:07:09 by snicolet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=clang
FLAGS=-Wall -Werror -Wextra -Weverything -fsanitize=address
MLX=./minilibx_macos
MLXFLAGS=-lmlx -framework OpenGL -framework AppKit
LIBFT=../libft/
OBJ=main.o
NAME=fdf

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)  -L $(LIBFT) -lft $(MLXFLAGS)
%.o: %.c
	$(CC) -c $< $(FLAGS) -I $(MLX) -I $(LIBFT)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
