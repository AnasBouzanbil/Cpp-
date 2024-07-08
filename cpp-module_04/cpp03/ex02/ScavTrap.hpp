#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap 
{
	public :
		void attack(const std::string& string);
		ScavTrap(ScavTrap& copy);
		ScavTrap(std::string nn);
		ScavTrap& operator=(ScavTrap& s);
		ScavTrap();
		~ScavTrap();
		void guardGate();
	private :

};

#endif