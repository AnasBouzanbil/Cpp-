#include "Dog.hpp"


Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(Dog& dog)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain(*dog.brain);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(Dog& dog)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if(this != &dog)
	{
		delete brain;
		this->brain = new Brain(*dog.brain);
	}
	return *this;
}

Brain* Dog::getBrain() const
{
	return brain;
}

void Dog::makeSound() const
{
	std::cout << "How How" << std::endl;
}

