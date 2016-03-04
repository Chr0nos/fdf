# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/27 16:01:14 by snicolet          #+#    #+#              #
#    Updated: 2016/03/04 17:06:27 by snicolet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ocl
CC=clang
FLAGS=-Wall -Werror -Wextra -Weverything -Ofast -march=native -mtune=native -fomit-frame-pointer -pipe
OBJ=ocl_init.o ocl_clean.o ocl_display_devices.o ocl_kernel_bufferize.o \
	ocl_strerror.o ocl_kernel_init.o \
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
