# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/08 17:19:09 by mpoussie          #+#    #+#              #
#    Updated: 2023/07/09 02:08:07 by mpoussie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

SRCS =	src/main.c \
		src/imput_check.c \
		src/init.c \
		src/stack.c \
		src/swap.c \
		src/utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
