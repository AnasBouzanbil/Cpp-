
NAME = harlFilter

SRC = main.cpp Harl.cpp

FLAGS = c++ -std=c++98 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
	@$(FLAGS) $(SRC) -o $(NAME)

clean :
	@rm -rf $(NAME)


fclean: clean

re: fclean all
