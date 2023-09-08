# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/08 17:19:09 by mpoussie          #+#    #+#              #
#    Updated: 2023/09/06 15:19:31 by mpoussie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft

SRCS =	src/check_args.c \
		src/handler_index.c \
		src/handler_sort.c \
		src/utils.c \
		src/move.c \
		src/move2.c \
		src/main.c \

OBJS = $(SRCS:.c=.o)
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
