

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void functiontest(Animal& animal)
{
	std::cout << "======= functiontest ======== " << std::endl;
	std::cout << "Animal type is : " << animal.getType() << std::endl;
	std::cout << "The sound of " << animal.getType() << " is : ";
	animal.makeSound();
	std::cout << "=============================" << std::endl;
}

int main()
{
	{
			Animal* meta[10];
			std::cout << "\e[1;36m-------- Creating Dog objects ----------\e[0m" << std::endl;
			for (int i = 0; i < 5; i++)
				meta[i] = new Dog();
			std::cout << "\e[1;34m-------- Creating Cat objects ----------\e[0m" << std::endl;
			for (int i = 5; i < 10; i++)
				meta[i] = new Cat();
			std::cout << "\e[4;35m-------- Functiontest ---------- \e[0m" << std::endl;
			for (int i = 0; i < 10; i++)
				functiontest(*meta[i]);
			std::cout << "\e[4;33m-------- Delete all objects ----------\e[0m" << std::endl;
			for (int i = 0; i < 10; i++)
				delete meta[i];
	}
	{
		std::cout << "\e[1;36m-------- More tests ----------\e[0m" << std::endl;
		Dog dog;
		Cat cat;
		dog.getBrain()->set_ideas("I am a dog", 0);
		cat.getBrain()->set_ideas("I am a cat", 0);
		Dog dog2 = dog;
		Cat cat2 = cat;
		dog2.getBrain()->set_ideas("I am a dog2", 0);
		functiontest(dog);
		functiontest(dog2);
		std::cout << "=============================\e[1;36m" << std::endl;
	}
	//{
	//	Animal *animal = new Animal();
	//}
}
