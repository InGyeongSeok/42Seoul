# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/25 12:55:28 by inseok            #+#    #+#              #
#    Updated: 2023/06/25 18:46:27 by inseok           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
OBJS = ${SRC:.c=.o}
CC = cc
FLAGS = -Wall -Wextra -Werror

SRC =	ft_printf.c \
		printf_c.c  \
		printf_s.c  \
		printf_p.c  \
		printf_d.c  \
		printf_u.c  \
		printf_x.c  \
		printf_utils.c\
		libft/ft_strlen.c




OBJ = $(OBJS)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re