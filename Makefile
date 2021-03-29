# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cloud <cloud@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 15:39:17 by cloud             #+#    #+#              #
#    Updated: 2021/01/26 15:47:31 by cloud            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = conv_d_next.c \
flagdup.c \
ft_atoi.c \
ft_conv_c.c \
ft_conv_d.c \
ft_conv_p.c \
ft_conv_s.c \
ft_conv_u.c \
ft_conv_x.c \
ft_hex.c \
ft_limit.c \
ft_putchar.c \
ft_puthex.c \
ft_putnbr.c \
ft_putstr.c \
ft_putu.c \
ft_strdup.c \
ft_strlen.c \
hex_ex.c \
init_struct.c \
nbr_ex.c \
nbr_u.c \
read_flag.c \
start_printf.c \
transit.c \

OBJ = ${SRC:.c=.o}

NAME = libftprintf.a

LINK = ar rc

$(NAME):		$(OBJ)
	$(LINK)		$(NAME) 	$(OBJ)

all:		$(NAME)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re