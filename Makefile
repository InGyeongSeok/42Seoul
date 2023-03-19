SRC =   ft_atoi.c		\
		ft_bzero.c      \
        ft_isalnum.c    \
        ft_isalpha.c    \
        ft_isascii.c    \
        ft_isdigit.c    \
        ft_isprint.c    \
        ft_memcpy.c     \
        ft_memmove.c    \
        ft_memset.c     \
        ft_strlcat.c    \
        ft_strlcpy.c    \
        ft_strlen.c     \
        ft_strncmp.c	\
		ft_memchr.c 	\
		ft_memcmp.c 	\
		ft_strchr.c 	\
		ft_strnstr.c 	\
		ft_strrchr.c 	\
		ft_tolower.c 	\
		ft_toupper.c

OBJS = ${SRC:.c=.o}
CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libft.a

$(NAME): $(OBJS)
	ar rcus $@ $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

all: $(NAME)

re: fclean all

.PHONY: all clean fclean re


