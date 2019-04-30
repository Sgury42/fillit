# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgury <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/25 11:12:14 by sgury             #+#    #+#              #
#    Updated: 2019/04/30 16:01:39 by sgury            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = main.c split_file.c tetri_is_valid.c fill_grid.c delete.c \

OBJS = $(SRCS:.c=.o)

LIBFT = ./libft/libft.a

INCLUDES = fillit.h

CFLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(SRCS) $(LIBFT)

%.o: %.c $(LIBFT)
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INCLUDES) 

$(LIBFT):
	make -C libft/

clean:
	rm -rf $(OBJS)
	make -C libft/ fclean

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re fclean all clean
