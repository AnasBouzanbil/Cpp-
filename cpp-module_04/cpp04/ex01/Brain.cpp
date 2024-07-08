
#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(Brain &brain)
{
	int	i;
	std::cout << "Brain copy constructor called" << std::endl;

	i = 0;
	while (i < 100)
	{
		ideas[i] = brain.ideas[i];
		i++;
	}
}

Brain& Brain::operator=(Brain &brain)
{
	std::cout << "Brain assignation operator called" << std::endl;
	int i;
	i = 0;
	while (i < 100)
	{
		ideas[i] = brain.ideas[i];
		i++;
	}
	return (*this);
}

void Brain::set_ideas(std::string idea, int index)
{
	if (index >= 0 && index < 100)
		ideas[index] = idea;
	else 
		std::cout << "Index out of range" << std::endl;
}

std::string Brain::get_ideas(int index) const
{
	if (index >= 0 && index < 100)
		return ideas[index];
	else 
		std::cout << "Index out of range" << std::endl;
	return "";
}
