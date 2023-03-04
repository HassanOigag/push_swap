# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/22 14:34:11 by hoigag            #+#    #+#              #
#    Updated: 2023/03/03 23:20:35 by hoigag           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_puthex.c ft_putunbr.c ft_puthex_long.c
OBJS = $(SRCS:.c=.o)

all: $(NAME) 

$(NAME): $(OBJS)
	@ar -rcs $@ $^ 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all