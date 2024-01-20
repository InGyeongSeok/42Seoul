# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/25 12:55:28 by inseok            #+#    #+#              #
#    Updated: 2023/06/26 08:50:19 by inseok           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
OBJS = ${SRCS:.c=.o}


SRCS =	ft_printf.c \
		printf_c.c  \
		printf_s.c  \
		printf_p.c  \
		printf_d.c  \
		printf_u.c  \
		printf_x.c  \
		printf_utils.c

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re