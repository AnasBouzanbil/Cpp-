NAME = zombie
src = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
all : $(NAME)
$(NAME) : $(src)
	c++ -Wall -Wextra -Werror -std=c++98  $(src) -o $(NAME)
clean :
	rm -rf $(NAME)
fclean : 
	clean
re : clean all