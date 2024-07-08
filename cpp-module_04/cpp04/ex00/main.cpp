#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


void testfunc(Animal& a)
{
	
	std::cout << a.getType() << " " << std::endl;
	a.makeSound();

}

int main()
{
	{
	const Animal* meta = new Animal(); 
	const Animal* j = new Dog(); 
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); 
	j->makeSound();
	meta->makeSound();
	delete i;
	delete j;
	delete meta;
	}
	{
		std::cout << "\t\t---------My Tests---------" << std::endl;
		Cat cat;
		Dog dog;
		Cat cat2(cat);
		
		std::cout << "cat2 type: " << cat2.getType() << std::endl;
		std::cout << "calling testfunc(cat)" << std::endl;
		testfunc(cat);
		std::cout << "calling testfunc(dog)" << std::endl;
		testfunc(dog);
	}

	{
		std::cout << "\t\t---------Wrong animal tests---------" << std::endl;
		WrongAnimal* meta = new WrongAnimal();
		WrongAnimal* i = new WrongCat();
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		std::cout << meta->getType() << " " << std::endl;
		meta->makeSound();
	}
}
