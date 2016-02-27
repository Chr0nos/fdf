# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/27 16:01:14 by snicolet          #+#    #+#              #
#    Updated: 2016/02/27 16:06:49 by snicolet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ocl
CC=clang
FLAGS=-Wall -Werror -Wextra -Weverything -Ofast -march=native -mtune=native -fomit-frame-pointer
OBJ=ocl_init.o ocl_clean.o ocl_display_devices.o \
	main.o
LIBFT=../libft

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -I $(LIBFT)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -L $(LIBFT) -lft -framework OpenCL

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
