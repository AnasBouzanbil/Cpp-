/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:41:37 by abouzanb          #+#    #+#             */
/*   Updated: 2023/06/21 23:42:44 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap constructor called" << std::endl;
	hit		=	10;
	enegry	=	10;
	damage	=	0;
}
ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap constructor called" << std::endl;

	string	=	name;
	hit		=	10;
	enegry	=	10;
	damage	=	0;
}

ClapTrap::ClapTrap(ClapTrap& newe)
{
	std::cout << "Copy constroucter is called" << std::endl;
	
	hit		= newe.hit;
	string	= newe.string;
	enegry	= newe.enegry;
	damage	= newe.damage;
}

ClapTrap& ClapTrap::operator=(ClapTrap& newe)
{
	std::cout << "ClapTrap operator= called" << std::endl;

	hit		= newe.hit;
	string	= newe.string;
	enegry	= newe.enegry;
	damage	= newe.damage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}
void ClapTrap::attack(const std::string& target)
{
	if (hit > 0 && enegry > 0)
	{
		std::cout << "ClapTrap " << string << " attack " << target << ", causing " << damage << " points of damage!" << std::endl;
		hit--;
		enegry--;
	}
	else
		std::cout << "ClapTrap " << string << " is dead" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit > 0 && enegry > 0)
	{
		std::cout << "ClapTrap " << string << " get Damage, and he got " << amount << " point of damage" << std::endl;
		hit -= amount;
		enegry--;
	}
	else 
		std::cout << "ClapTrap " << string << " already dead" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (amount < 0)
		std::cout << "Error amount point are not a positive number" << std::endl;
	else if (hit < 0)
		std::cout << "ClapTrap " <<string << " is dead" << std::endl;
	else {
		std::cout << "ClapTrap " << string << "got " << amount << " of hit point" << std::endl;
		hit += amount;
		if (hit > 10)
			hit = 10;
		enegry--;
	}
}