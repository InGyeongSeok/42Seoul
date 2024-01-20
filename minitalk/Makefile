# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inseok <inseok@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/23 12:50:28 by inseok            #+#    #+#              #
#    Updated: 2023/10/03 09:03:47 by inseok           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MFLAGS = -fsanitize=address

HEADER = minitalk.h
HEADER_BONUS = minitalk_bonus.h

SERVER_SRC	= server.c
SERVER_SRC_BONUS = server_bonus.c
SERVER_OBJS = ${SERVER_SRC:.c=.o}

CLIENT_SRC	= client.c
CLIENT_SRC_BONUS = client_bonus.c
CLIENT_OBJS = ${CLIENT_SRC:.c=.o}

PRINTF_DIR = lib/ft_printf
PRINTF_NAME = libftprintf
PRINTF = $(PRINTF_DIR)/$(PRINTF_NAME).a

LIBFT_DIR = lib/libft
LIBFT_NAME = libft
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME).a


OBJ = $(OBJS)

all:server client

server: $(LIBFT) $(PRINTF) $(SERVER_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

client: $(LIBFT) $(PRINTF) $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

bonus:
	make HEADER=$(HEADER_BONUS) SERVER_SRC=$(SERVER_SRC_BONUS) CLIENT_SRC=$(CLIENT_SRC_BONUS) all



clean:
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS) ${SERVER_SRC_BONUS:.c=.o} ${CLIENT_SRC_BONUS:.c=.o}

fclean: clean
	rm -f server client
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re:
	make fclean
	make all

.PHONY: fclean all clean re