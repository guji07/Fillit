NAME = fillit
FILES = init_grid.c\
		read_grid.c\
		solver.c\
		main.c\
		freall.c

OBJ			= $(patsubst %.c, %.o, $(FILES))
FLAGS		=  -Wall -Werror -Wextra
HEADER		= libft.h

all: $(NAME)

.PHONY: clean fclean re

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) ./libft/libft.a

%.o: %.c $(HEADER)
	gcc -I . $(FLAGS) $< -c -o $@

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re: fclean all

