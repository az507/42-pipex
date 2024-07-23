# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achak <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 14:18:21 by achak             #+#    #+#              #
#    Updated: 2024/01/25 13:43:48 by achak            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_dprintf
CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar -rc

SRCS = ft_dprintf.c ft_printptr.c

OBJS = $(SRCS:.c=.o)

all: $(OBJS)

#$(NAME): $(OBJS)
#	$(AR) $(NAME) $(OBJS)
#	ranlib $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
