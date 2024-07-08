#include "harl.hpp"

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void Harl::info(void)
{
		std::cout << "I !have some info\n";
}

void Harl::warning(void)
{
	std::cout << "I think that you do not have to do it\n";
}

void Harl::error(void)
{
	std::cout << "I told you that this is an error\n";
}

void Harl::complain(std::string level) 
{
	void (Harl::*fun[4])(void) = { &Harl::debug, &Harl::info , &Harl::warning, &Harl::error}; // this is an array of pointers to functions
	const char* index[4] = {"DEBUG", "INFO","WARNING",  "ERROR"}; // this is an array of strings
	int i; 
	i = 0;
	while (i < 4)
	{
		if (level == index[i]) // if the level is equal to the string at the index i 
			(this->*fun[i])(); // we call the function at the index i
		i++; 
	}

}  

