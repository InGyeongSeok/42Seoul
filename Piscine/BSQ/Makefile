# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 14:10:57 by seonglim          #+#    #+#              #
#    Updated: 2023/02/02 08:40:57 by seonglim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJS = main.o check.o map.o others.o

NAME = bsq

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o : %.c ft.h
	$(CC) $(CFLAGS) -c $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

all : $(NAME)

re : fclean all
