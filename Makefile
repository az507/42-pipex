# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achak <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 11:18:54 by achak             #+#    #+#              #
#    Updated: 2024/02/22 14:26:48 by achak            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL	:= /bin/bash
NAME	:= pipex
B_NAME	:= pipex
CC	:= cc -g -Wall -Werror -Wextra
SRCS	= $(wildcard pipex_dir/*.c)
B_SRCS	= $(wildcard pipex_bonus_dir/*.c)
OBJ	= $(SRCS:.c=.o)
B_OBJ	= $(B_SRCS:.c=.o)
LIBFT	= libft
TEMP	= infile outfile here_doc pipex_dir/infile pipex_dir/outfile \
	  pipex_bonus_dir/infile pipex_bonus_dir/outfile

all:	$(NAME)
	$(shell ls -al ~ > infile)

$(NAME): $(LIBFT) $(OBJ)
	$(MAKE) all -C $(LIBFT)
	$(CC) -L libft/libft.a $(OBJ) $(LIB_OBJ) -I libft/libft.h -o $(NAME)

LIB_OBJ	= libft/*.o libft/ft_dprintf/*.o

#bonus:	clean $(B_NAME)

#$(B_NAME): $(LIBFT) $(B_OBJ)
#	$(MAKE) all -C $(LIBFT)
#	$(CC) -L libft/libft.a $(B_OBJ) $(LIB_OBJ) -I libft/libft.h -o $(B_NAME)

%.o:%.c
	$(CC) -c $^ -o $@

clean:
	rm -rf $(OBJ)
	rm -rf $(B_OBJ)
	rm -rf $(NAME)
	rm -rf $(B_NAME)
	if [ -d $(LIBFT) ]; then $(MAKE) clean -C $(LIBFT); fi

fclean:	clean
	rm -rf $(NAME)
	rm -rf $(B_NAME)
	rm -rf $(TEMP)
ifneq "$(wildcard $(LIBFT) )" ""
	$(MAKE) fclean -C $(LIBFT)
endif

re:	fclean all

bonus:	fclean $(B_OBJ) $(LIBFT)
	$(MAKE) all -C $(LIBFT)
	$(CC) -L libft/libft.a $(B_OBJ) $(LIB_OBJ) -o $(B_NAME)

.PHONY:	all clean fclean re bonus
