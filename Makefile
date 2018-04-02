# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysibous <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/23 18:15:35 by ysibous           #+#    #+#              #
#    Updated: 2018/03/28 15:49:54 by ysibous          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = gcc
CFLAGS = -Wall -Wextra -Werror -o

FILES = main.c
FILES += handle_options.c

SRC = $(addprefix src/, $(FILES))

all: $(NAME)

LIBFT = includes/libft/libft.a

mlibft.a: 
		make -C includes -C libft re

$(NAME): mlibft.a
	$(CC) $(CFLAGS) $(NAME) $(SRC) $(LIBFT)
