NAME = ex00
src = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp

Flg = -Wall -Wextra -Werror -std=c++98

all: $(NAME)


$(NAME): $(src) 
	@c++ $(Flg) $(src) -o $(NAME)

clean:
	@rm -rf $(NAME)

fclean: clean

re: fclean all