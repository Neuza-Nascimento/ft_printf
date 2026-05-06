# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nedo-nas <nedo-nas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/29 14:35:02 by nedo-nas          #+#    #+#              #
#    Updated: 2026/05/05 10:41:41 by nedo-nas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

FLAGS = -Wall -Wextra -Werror

SOURCES = srcs/ft_printf.c \
		srcs/ft_puthex.c \
		srcs/ft_putnbr.c \
		srcs/ft_putstr.c \
		srcs/ft_putchar.c \
		srcs/print_nbr_hex.c \

OBJ = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c 
	$(CC) $(FLAGS) -I include -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	
re: fclean all
	
.PHONY: all clean fclean re
