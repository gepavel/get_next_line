
NAME =  gnl

COMPILER = clang

FLAGS = -Wall -Werror -Wextra ##-fsanitize=address -g3

HEADERFILE = get_next_line.h

SRC = get_next_line.c	get_next_line_utils.c		main.c 

all: $(NAME)

$(NAME): $(SRC)
	$(COMPILER) $(FLAGS) $(SRC) -o $(NAME)
	./$(NAME)

clean: 
	rm -rf $(NAME)
fclean: clean

re: clean all

.PHONY: all clean fclean re
