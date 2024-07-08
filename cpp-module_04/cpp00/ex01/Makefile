NAME = a.out 
CFLAGS = c++ -Wall -Wextra -Werror -std=c++98
src = contact.cpp main.cpp phone_number.cpp
all : $(NAME)

$(NAME) : $(src)
	@$(CFLAGS) $(src) -o $(NAME) -lreadline
clean :
	@rm -f $(NAME)
fclean : clean
	
re : fclean all 