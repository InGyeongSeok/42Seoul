CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC = srcs/
INC = includes/

NAME = libft.a

OBJFILES = $(SRC)ft_putchar.o $(SRC)ft_swap.o $(SRC)ft_putstr.o $(SRC)ft_strlen.o $(SRC)ft_strcmp.o

$(NAME): $(OBJFILES)
	ar rcus $@ $(OBJFILES)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -I $(INC)

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

all: $(NAME)

re: fclean all

.PHONY: all clean fclean re