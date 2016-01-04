# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snicolet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/28 16:24:25 by snicolet          #+#    #+#              #
#*   Updated: 2016/01/04 16:53:36 by snicolet         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

CC=clang
FLAGS=-Wall -Werror -Wextra -Weverything
LIBFT=../libft
DRAW_PATH=./draw/
X11=-lXext -lX11 -lm
LIBS=-L$(DRAW_PATH) -ldraw -L$(LIBFT) -lft $(X11)
INCLUDES=-I$(LIBFT) -I$(DRAW_PATH) -I.

OBJ=main.o
NAME=fdf

all: $(NAME)

lis:
	make -C $(LIBFT) EXTRA_FLAGS= BTREE=
	make -C $(DRAW_PATH) FLAGS="$(FLAGS)" LIBFT=../$(LIBFT)

prename: $(OBJ)

$(NAME): $(OBJ) lis
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBS)

%.o: %.c
	$(CC) -c $< $(FLAGS) $(INCLUDES)

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
