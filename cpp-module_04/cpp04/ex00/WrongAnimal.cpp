#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal constructor called" << std::endl;
	type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &animal)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = animal;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal &animal)
{
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	return (animal);
}

std::string WrongAnimal::getType()
{
	return (type);
}

void WrongAnimal::makeSound()
{
	std::cout << "WrongAnimal sound" << std::endl;
}
