NAME = libft.a
FILES = ft_atoi.c\
		ft_isdigit.c\
		ft_lstdelone.c\
		ft_memccpy.c\
	   	ft_memmove.c\
		ft_putendl_fd.c\
		ft_strcat.c\
		ft_strdel.c\
		ft_strjoin.c\
		ft_strncat.c\
		ft_strnstr.c\
		ft_strtrim.c\
		ft_bzero.c\
		ft_isprint.c\
		ft_lstiter.c\
		ft_memchr.c\
		ft_memset.c\
		ft_putnbr.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_strlcat.c\
		ft_strncmp.c\
		ft_strrchr.c\
		ft_tolower.c\
		ft_isalnum.c\
		ft_itoa.c\
		ft_lstmap.c\
		ft_memcmp.c\
		ft_putchar.c\
		ft_putnbr_fd.c\
		ft_strclr.c\
		ft_strequ.c\
		ft_strlen.c\
		ft_strncpy.c\
		ft_strsplit.c\
		ft_toupper.c\
		ft_isalpha.c\
		ft_lstadd.c\
		ft_lstnew.c\
		ft_memcpy.c\
		ft_putchar_fd.c\
		ft_putstr.c\
		ft_strcmp.c\
		ft_striter.c\
		ft_strmap.c\
		ft_strnequ.c\
		ft_strstr.c\
		ft_isascii.c\
		ft_lstdel.c\
		ft_memalloc.c\
		ft_memdel.c\
		ft_putendl.c\
		ft_putstr_fd.c\
		ft_strcpy.c\
		ft_striteri.c\
		ft_strmapi.c\
		ft_strnew.c\
		ft_strsub.c\
		ft_strnlen.c\
		ft_isupper.c\
		ft_islower.c\
		ft_strrev.c\
		ft_lstaddback.c\
		ft_strndup.c\
		ft_swapfree.c\
		get_next_line.c\
		ft_strchrn.c\
		ft_strset.c\
		ft_sqrt.c\
		ft_lstfreeone.c

OBJ			= $(patsubst %.c, %.o, $(FILES))
FLAGS		=  -Wall -Werror -Wextra
HEADER		= libft.h

all: $(NAME)

.PHONY: clean fclean re

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	gcc -I . $(FLAGS) $< -c -o $@

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re: fclean all
