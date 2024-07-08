NAME = megaphone
CFLAGS = c++ -Wall -Wextra -Werror -std=c++98
src = megaphone.cpp
all : $(NAME)

$(NAME) : $(src)
	@$(CFLAGS) $(src) -o $(NAME)
clean :
	@rm -f $(NAME)
fclean : 
	clean
re : fclean all 