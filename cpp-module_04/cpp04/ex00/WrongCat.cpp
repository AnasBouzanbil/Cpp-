#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat constructor called" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(WrongCat& cat)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = cat;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat& cat)
{
	std::cout << "WrongCat assignation operator called" << std::endl;
	return cat;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat sound" << std::endl;
}


