#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/11 18:01:35 by gmordele          #+#    #+#              #
#    Updated: 2017/03/22 22:30:43 by gmordele         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	libftprintf.a

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

SRC			=	ft_printf.c				parse_conv_spec.c			ft_strcpy.c					\
				handle.c				ft_strequ.c					ft_strlen.c					\
				ft_putstr.c				decimal_itoa.c				long_decimal_itoa.c			\
				llong_decimal_itoa.c	handle_decimal_int.c		handle_unsigned_int.c		\
				handle_octal.c			handle_udecimal.c			handle_hex.c				\
				octal_itoa.c			ulong_octal_itoa.c			ullong_octal_itoa.c			\
				hex_itoa.c				ulong_hex_itoa.c			ullong_hex_itoa.c			\
				handle_pointer.c		pointer_itoa.c				udec_itoa.c					\
				ulong_udec_itoa.c		ullong_udec_itoa.c			handle_char.c				\
				buff_char.c				buff_wchar.c				handle_string.c				\
				buff_strwch.c			buff_string.c				ft_strdup.c					\
				buff.c					ft_strnequ.c				handle_color.c				\
				print_col.c				handle_bin.c				bin_itoa.c					\
				ulong_bin_itoa.c		ullong_bin_itoa.c

OBJ			=	$(SRC:%.c=%.o)

DEST_SRC	=	src/

DEST_INC	=	./include/


all 		:	$(NAME)

$(NAME)		:	$(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o			:	$(DEST_SRC)%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(DEST_INC)

clean		:
	rm -f $(OBJ)

fclean		:	clean
	rm -f $(NAME)

re			:	fclean all

.PHONY:all clean fclean re
