Name = ex01

src = main.cpp Fixed.cpp

all : $(Name)

Flags = c++ -Wall -Wextra -Werror -std=c++98

$(Name) : $(src)
	@$(Flags) $(src) -o $(Name)

clean :
	@rm -f $(Name)

fclean : clean

re : clean all
