# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snicolet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/18 11:43:48 by snicolet          #+#    #+#              #
#    Updated: 2016/01/18 12:26:24 by snicolet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftmath.a
FLAGS=-Wall -Wextra -Werror -Weverything
OBJ=ft_double_to_fixed.o \
	ft_fixed_to_real.o \
	ft_fixed_decimal.o

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) -c $(FLAGS) $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
