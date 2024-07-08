#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string nn)
{
	std::cout << "The constroucter of ScavClap is called" << std::endl;
	string	=	nn;
	damage	=	20;
	enegry	=	50;
	hit		=	100;
}
ScavTrap::ScavTrap(ScavTrap& copy) : ClapTrap(copy)
{
	std::cout << "The constroucter of ScavClap is called" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap& copy)
{
	std::cout << "The constroucter of ScavClap is called" << std::endl;
	string	=	copy.string;
	hit		=	copy.hit;
	enegry	=	copy.enegry;
	damage	=	copy.damage;
	return *this;   
}

ScavTrap::ScavTrap()
{
	std::cout << "The constroucter of ScavClap is called" << std::endl;
	hit		=	100;
	enegry	=	50;
	damage	=	20;
}

void ScavTrap::guardGate()
{
	if (hit < 0 || enegry < 0)
		std::cout << string <<" is Dead" << std::endl;
	
	else
		std::cout << string <<" is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (hit > 0 && enegry > 0)
	{
		std::cout << "ScavTrap : " << string << " attack " << target << ", causing " << damage << " points of damage!" << std::endl;
		hit--;
		enegry--;
	}
	else
		std::cout << "ScavTrap : "<<  string << " is dead, So he can not ATTACK" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "The destroucter of ScavClap is called" << std::endl;
}