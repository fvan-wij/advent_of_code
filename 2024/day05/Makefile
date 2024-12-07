CC = c++
FLAGS = -Wall -Werror -Wextra

NAME = app

SRC = $(notdir $(PWD)).cpp
OBJ = $(notdir $(PWD)).o

ifdef DEBUG
	FLAGS		:= -Wall -Werror -Wextra -g -fsanitize=address
else
	FLAGS		:= -Wall -Werror -Wextra -g -fsanitize=address
endif


$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ): $(SRC)
	$(CC) $(FLAGS) -c $(SRC)

debug:
	$(MAKE) DEBUG=1

clean:
	rm -f $(NAME) $(OBJ)
