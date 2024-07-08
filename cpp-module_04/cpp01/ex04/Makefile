NAME = sed

SRCS = main.cpp

FLAGS = c++ -std=c++98 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRCS)
	@$(FLAGS) $(SRCS) -o $(NAME)

clean :
	@rm -rf $(NAME)

fclean: clean

re: fclean all