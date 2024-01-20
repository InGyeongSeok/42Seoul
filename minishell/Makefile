# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonglim <seonglim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 19:09:20 by seonglim          #+#    #+#              #
#    Updated: 2023/11/04 19:08:38 by seonglim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS =
LFLAGS = -lreadline

MCHECK = -fsanitize=address

SRCS = main.c ft_util.c ft_split.c parse.c solve.c redirect.c vector.c\
		my_util.c my_util2.c cmd_split.c single_cmd.c pipe.c pipe_child.c\
		here_doc_sub.c\
		tree.c\
		cd.c exit.c pwd.c env.c export.c export2.c unset.c echo.c

OBJ_DIR = .objdir
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

HEADER = minishell.h

NAME = minishell

CFLAGS += -Wall -Wextra -Werror
# CFLAGS += $(MCHECK)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ $(OBJS)

$(OBJ_DIR)/%.o : %.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

all : $(NAME)

re :
	@make fclean
	@make all

.PHONY : all re clean fclean
