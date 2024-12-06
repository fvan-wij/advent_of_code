CC = c++
FLAGS = -Wall -Werror -Wextra

NAME = app

SRC = $(notdir $(PWD)).cpp
OBJ = $(notdir $(PWD)).o

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ): $(SRC)
	$(CC) $(FLAGS) -c $(SRC)

clean:
	rm -f $(NAME) $(OBJ)
