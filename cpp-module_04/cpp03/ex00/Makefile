NAME = ex00

src = main.cpp CLAPTRAP.cpp 

all: $(NAME)

$(NAME): $(src)
	@c++ -std=c++98 -Wall -Wextra -Werror $(src) -o $(NAME)

clean:
	@rm -rf $(NAME)
fclean: clean

re: fclean all