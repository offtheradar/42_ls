# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/03 19:08:41 by ysibous           #+#    #+#              #
#    Updated: 2018/05/07 21:05:07 by ysibous          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = clang -g
CFLAGS = -Wall -Wextra -Werror -o

FILES = main.c
FILES += ft_ls.c
FILES += handle_options.c
FILES += init_file_info.c
FILES += load_file_info.c
FILES += print_lst.c
FILES += order_lst.c
FILES += comparaison_helpers.c

SRC = $(addprefix src/, $(FILES))

all: $(NAME)

re: fclean all

clean:
		rm -rf build

fclean: clean
		rm -rf $(NAME)

LIBFT = includes/libft/libft.a

mlibft.a: 
	make -C includes -C libft

$(NAME): mlibft.a
	$(CC) $(CFLAGS) $(NAME) $(SRC) $(LIBFT) #-fsanitize=address
