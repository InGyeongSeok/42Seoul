NAME = rush-02

SRC = *.c

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC)

clean:
	rm -f *.o *.gch *.swp

fclean: clean
	rm -f $(NAME)

re: fclean all