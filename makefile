# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgury <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/25 11:12:14 by sgury             #+#    #+#              #
#    Updated: 2019/05/01 17:01:07 by pvinson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = main.c split_file.c tetri_is_valid.c fill_grid.c delete.c normalize.c \
	   ft_print_tetri_table.c
OBJS = $(SRCS:.c=.o)

INCLUDES = fillit.h tetri_color.h

LIBFT = ./libft/libft.a

CFLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

%.o: %.c $(LIBFT)
	$(CC) $(CFLAGS)  -c $< $(addprefix -I,$(INCLUDES)) -o $@

$(LIBFT):
	make -C libft/

clean:
	rm -rf $(OBJS)
	make -C libft/ fclean

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re fclean all clean
