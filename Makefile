# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aserguie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/20 15:26:00 by aserguie          #+#    #+#              #
#    Updated: 2017/08/30 13:47:25 by aserguie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

CC=gcc

CFLAGS=-Wall -Werror -Wextra

SRC=ft_printf.c ft_display.c ft_itoa_base.c ft_parsing.c ft_putchar.c \
	ft_putstr.c ft_atoi.c ft_check.c ft_tolower.c ft_isdigit.c ft_strlen.c \
	ft_strdup.c decimal_itoa.c long_decimal_itoa.c llong_decimal_itoa.c

OBJ=$(SRC:%.c=%.o)

DEST_SRC=./src/

DEST_INC=./include/


all:	$(NAME)

$(NAME):$(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o:$(DEST_SRC)%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(DEST_INC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

/*.PHONY:all clean fclean re*/
