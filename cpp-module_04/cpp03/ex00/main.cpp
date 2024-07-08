#include "ClapTrap.hpp"

int main()
{
	ClapTrap clapTrap("Robot1");
	ClapTrap Army = clapTrap;
	ClapTrap backup;
	clapTrap.attack("Enemy1");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(3);
	clapTrap.attack("Enemy2");
	clapTrap.takeDamage(12);
	clapTrap.takeDamage(12);
	clapTrap = backup;
	clapTrap.attack("charaf");
	clapTrap.beRepaired(3);
	return 0;
}