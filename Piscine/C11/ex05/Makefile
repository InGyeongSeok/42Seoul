CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC = calculator.c putnuber.c main.c
INC = .

NAME = do-op

OBJFILES = calculator.o putnuber.o main.o 

$(NAME): $(OBJFILES)
	$(CC) $(CFLAGS) $(OBJFILES) -o $@
.c.o:
	$(CC) $(FLAGS) -c $< -o $@ -I $(INC)

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

all: $(NAME)

re: fclean all

.PHONY: all clean fclean re
