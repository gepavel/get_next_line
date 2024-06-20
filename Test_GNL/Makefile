
NAME =  gnl

BONUSNAME = bonus

COMPILER = clang

FLAGS = -Wall -Werror -Wextra -D BUFFERSIZE=7 -fsanitize=address -g3

HEADERFILE = get_next_line.h

HFILE_BONUS = get_next_line_bonus.h

SRC = get_next_line.c	get_next_line_utils.c		main.c 

BONUS_SRC = get_next_line_bonus.c   get_next_line_utils_bonus.c	 main_bonus.c

all: $(NAME)

$(NAME): $(SRC)
	$(COMPILER) $(FLAGS) $(SRC) -o $(NAME)
	./$(NAME)

$(BONUSNAME): $(BONUS_SRC)
	$(COMPILER) $(FLAGS) $(BONUS_SRC) -o $(BONUSNAME)
	./$(BONUSNAME)

clean: 
	rm -rf $(NAME)
	rm -rf $(BONUSNAME)
fclean: clean

re: clean all

.PHONY: all bonus clean fclean re
