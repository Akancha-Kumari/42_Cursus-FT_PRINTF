# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akumari <akumari@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 12:50:45 by akumari           #+#    #+#              #
#    Updated: 2024/11/22 09:19:33 by akumari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS=    ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c \
			ft_putunbr.c ft_putptr.c ft_puthex.c

OBJS	= ${SRCS:%.c=%.o}

CC = cc

FLAGS	= -Wall -Wextra -Werror

RM = rm -rf

LIBC = ar rcs

HEADER	= ft_printf.h

all: $(NAME) 

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -c $(SRCS) -I ./
	$(LIBC) $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all