# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psan-gre <psan-gre@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/11 16:55:38 by psan-gre          #+#    #+#              #
#    Updated: 2021/05/13 10:04:18 by fgata-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS := -Wall -Wextra -Werror -I. -g

SRC = list.c list_2.c getters.c printers.c

OBJS = $(SRC:.c=.o)

NAME = liblist.a

all: $(NAME)

test: re
	$(CC) $(CFLAGS) main.c -L. -llist

$(NAME): $(BONUS)
	$(CC) $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJS) $(PRINTOBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME) a.out*

re: fclean all

.PHONY: all clean fclean re
