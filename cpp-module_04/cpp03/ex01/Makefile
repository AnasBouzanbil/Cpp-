NAME = ex01

src = main.cpp CLAPTRAP.cpp  ScavTrap.cpp

all: $(NAME)

$(NAME): $(src)
	@c++ -std=c++98 -Wall -Wextra -Werror $(src) -o $(NAME)

clean:
	@rm -rf $(NAME)
fclean: clean

re: fclean all