NAME = ex03
src = HumanA.cpp HumanB.cpp Weapon.cpp main.cpp
flags = c++  -Wall -Wextra -Werror  -std=c++98
all : $(NAME)
$(NAME) : $(src)
	@$(flags) $(src) -o $(NAME)
clean :
	@rm -f $(NAME)
fclean : clean
re : fclean all