NAME = ex02
src = main.cpp
flags = g++ -Wall -Wextra -Werror
all : $(NAME)
$(NAME) : $(src)
	@$(flags) $(src) -o $(NAME)
clean :
	@rm -rf $(NAME)
fclean :
	clean
re : fclean all