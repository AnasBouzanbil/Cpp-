NAME = ex01
src = Zombie.cpp main.cpp zombieHorde.cpp
flags = g++ -Wall -Wextra -Werror
all : $(NAME)
$(NAME) : $(src)
	@$(flags) $(src) -o $(NAME)
clean :
	@rm -rf $(NAME)
fclean : clean

re : fclean all