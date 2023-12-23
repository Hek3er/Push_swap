# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 23:12:25 by azainabi          #+#    #+#              #
#    Updated: 2023/12/23 01:39:24 by azainabi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
AR = ar rc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a

SRC =	ft_print_digit.c ft_print_lhex.c ft_print_p.c ft_print_uhex.c \
		ft_print_unsigned.c ft_printf.c ft_putchar.c ft_putstr.c ../ft_libft/ft_strlen.c

COBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(COBJ)
	@$(AR) $@ $(COBJ)

%.o : %.c ft_printf.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(COBJ)
fclean: clean
	@rm -f $(NAME)
re: fclean all