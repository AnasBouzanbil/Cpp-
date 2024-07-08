NAME = Harl

FLAGS = c++  -Wall -Wextra -Werror  -std=c++98

src = harl.cpp main.cpp

all : $(NAME)

$(NAME) : $(src)

	@$(FLAGS) $(src) -o $(NAME)

clean :
	@rm -f $(NAME)

fclean : clean

re : clean all  