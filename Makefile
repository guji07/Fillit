NAME = fillit
FILES = init_grid.c\
		read_grid.c\
		solver.c\
		main.c\
		freall.c

OBJ			= $(patsubst %.c, %.o, $(FILES))
FLAGS		=  -Wall -Werror -Wextra -ggdb3
HEADER		= libft.h

all: $(NAME)

.PHONY: clean fclean re

$(NAME): $(OBJ)
	$(MAKE) -C libft all
	gcc -o $(NAME) $(OBJ) ./libft/libft.a

%.o: %.c $(HEADER)
	gcc -I . $(FLAGS) $< -c -o $@

clean:
	rm -f $(OBJ) && $(MAKE) clean -C ./libft

fclean:clean
	rm -f $(NAME) && $(MAKE) fclean -C ./libft

re: fclean all

