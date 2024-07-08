#include "Dog.hpp"


Dog::Dog()
{
    std::cout << "Dog constructor called" << std::endl;
    type = "Dog";
}

Dog::Dog(Dog& dog) : Animal(dog)
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(Dog& dog)
{
    std::cout << "Dog assignation operator called" << std::endl;
    return dog;
}

void Dog::makeSound() const
{
    std::cout << "How How" << std::endl;
}

