NAME = libft.a
OBJS = ${SRC:.c=.o}
OBJS_B = ${SRC_B:.c=.o}
CC = cc
FLAGS = -Wall -Wextra -Werror
ALL = mandatory
bonus = for_bonus

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
		ft_toupper.c	\
		ft_strjoin.c	\
		ft_substr.c		\
		ft_strdup.c		\
		ft_calloc.c		\
		ft_split.c		\
		ft_strtrim.c	\
		ft_itoa.c 	\
		ft_strmapi.c	\
		ft_striteri.c	\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c

SRC_B = ft_lstnew_bonus.c\
		ft_lstadd_front_bonus.c\
		ft_lstlast_bonus.c\
		ft_lstsize_bonus.c\
		ft_lstadd_back_bonus.c\
		ft_lstdelone_bonus.c	\
		ft_lstclear_bonus.c	\
		ft_lstiter_bonus.c	\
		ft_lstmap_bonus.c

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $(OBJS)
	rm -rf $(BONUS)
	touch $@

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	rm -f $(NAME)

bonus: $(OBJS) $(OBJS_B)
	ar rc $(NAME) $(OBJS) $(OBJS_B)
	rm -rf $(ALL)
	touch $@

re: fclean all

.PHONY: all clean fclean re
