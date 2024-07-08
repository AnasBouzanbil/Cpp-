#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "The defalut constroucter of FragClap is called" << std::endl;
	damage	=	30;
	enegry	=	100;
	hit		=	100;
}

void FragTrap::attack(const std::string& target)
{
	if (hit > 0 && enegry > 0)
	{
		std::cout << "FragTrap : "<< string << " attack " << target << ", causing " << damage << " points of damage!" << std::endl;
		hit--;
		enegry--;
	}
	else
		std::cout <<  string << " is dead, So he can not ATTACK" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap : Good work guys. we are going to win" << std::endl;
}
 
FragTrap::FragTrap(std::string nn) : ClapTrap(nn)
{
	std::cout << "The parameterized constructors of FragClap is called" << std::endl;
	damage	=	30;
	enegry	=	100;
	hit		=	100;
}

FragTrap::FragTrap(FragTrap& copy) : ClapTrap(copy)
{
	std::cout << "The copy constroucter of FragClap is called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "The destroucter of FragClap is called" << std::endl;
}

FragTrap&	FragTrap::operator=(FragTrap& copy)
{
	std::cout << "The operator= of FragClap is called" << std::endl;
	string	=	copy.string;
	hit		=	copy.hit;
	enegry	=	copy.enegry;
	damage	=	copy.damage;
	return *this;   
}
