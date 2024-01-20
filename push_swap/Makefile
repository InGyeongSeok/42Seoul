# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/02 14:01:12 by inseok            #+#    #+#              #
#    Updated: 2023/09/17 16:42:23 by inseok           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:%.c=%.o)

NAME = push_swap

SRCS = base.c \
	   swap.c \
	   push.c \
	   rotate.c\
	   reverse.c\
	   main.c \
	   parse.c \
	   parse_utils.c\
	   stack.c \
	   sort.c \
	   greedy_sort.c\
	   find_a.c\
	   rotate_ab.c


PRINTF_DIR = ./lib/ft_printf
PRINTF_NAME = libftprintf
PRINTF = $(PRINTF_DIR)/$(PRINTF_NAME).a

LIBFT_DIR = ./lib/libft
LIBFT_NAME = libft
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME).a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $@ $^

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re:
	make fclean
	make all

.PHONY: fclean all clean re


