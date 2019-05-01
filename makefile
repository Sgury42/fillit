# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgury <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/25 11:12:14 by sgury             #+#    #+#              #
#    Updated: 2019/05/01 11:42:54 by pvinson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = main.c split_file.c tetri_is_valid.c fill_grid.c delete.c
SRC_PATH = srcs/

OBJS = $(SRCS:.c=.o)
OBJ_PATH = objs/

INCLUDES = fillit.h
INC_PATH = includes/

LIBFT = ./libft/libft.a

CFLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(addprefix $(OBJ_PATH),$^) $(LIBFT)

%.o: $(SRC_PATH)%.c $(LIBFT)
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -o $(OBJ_PATH)$@ -c $< -I $(INC_PATH)$(INCLUDES) 

$(LIBFT):
	make -C libft/

clean:
	rm -rf $(OBJ_PATH)
	make -C libft/ fclean

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re fclean all clean
