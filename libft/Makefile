# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achak <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 15:53:42 by achak             #+#    #+#              #
#    Updated: 2024/02/08 16:26:20 by achak            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc -c
INCLUDE = libft.h
FLAGS = -Wall -Wextra -Werror
DPRINTF	= ft_dprintf
DPF_OBJ	= ft_dprintf/ft_dprintf.o ft_dprintf/ft_printptr.o
#OTHERS = $(shell ls -l | grep '^d' | awk '{print $NF}')
AR = ar rc
MAKE = make
SRCS = $(wildcard *.c)

#	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
#	ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
#	ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
#	ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_memcpy.c \
#	ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
#	ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
#	ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c main.c

OBJ =  $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(DPRINTF)
	$(CC)  $(FLAGS) $(SRCS)
	$(MAKE) all -C $(DPRINTF)
	$(AR)  $(NAME) $(OBJ) $(DPF_OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(DPRINTF)

fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -C $(DPRINTF)

re:	fclean all

.PHONY:	all clean fclean re
