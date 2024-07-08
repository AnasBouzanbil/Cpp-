

#ifndef WRONGANIMAL_HPP

# define WRONGANIMAL_HPP
#include <iostream>

class WrongAnimal{
	protected :
		std::string type;
	public :
	WrongAnimal();
	WrongAnimal(WrongAnimal &animal);
	~WrongAnimal();
	WrongAnimal &operator=(WrongAnimal &animal);
	std::string getType();
	void  makeSound(); // hERE IS THE DIFFERENCE BETWEEN ANIMAL AND WRONGANIMAL. THIS FUNCTION IS NOT VIRTUAL SO IT WILL NOT BE OVERRIDEN BY THE CHILDREN AND IT WILL PRINT THE SAME MESSAGE
};

#endif