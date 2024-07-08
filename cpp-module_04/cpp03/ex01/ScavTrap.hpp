#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap  // This class will inherit from ClapTrap class
{
	public :
		void attack(const std::string& string); // this is the function that will be used to attack and it will be overriden to print the right message
		ScavTrap(ScavTrap& copy); // this is the copy constructor
		ScavTrap(std::string nn);
		ScavTrap& operator=(ScavTrap& s);
		ScavTrap();
		~ScavTrap();
		void guardGate(); // this is the function that will be used to print the a message

};

#endif