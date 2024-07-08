/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 23:18:44 by abouzanb          #+#    #+#             */
/*   Updated: 2023/06/21 23:18:45 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ScavTrap.hpp"


ScavTrap::ScavTrap(std::string nn) : ClapTrap(nn)
{
	std::cout << "The parametrized constroucter of ScavClap is called" << std::endl;
	damage	=	20;
	enegry	=	50;
	hit		=	100;
}

ScavTrap::ScavTrap(ScavTrap& copy) : ClapTrap(copy)
{
	std::cout << "The copy constroucter of ScavClap is called" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap& copy)
{
	std::cout << "The operator= of ScavClap is called" << std::endl;
	string	=	copy.string;
	hit		=	copy.hit;
	enegry	=	copy.enegry;
	damage	=	copy.damage;
	return *this;   
}

ScavTrap::ScavTrap()
{
	std::cout << "The defalut constroucter of ScavClap is called" << std::endl;
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
		std::cout << string << " attack " << target << ", causing " << damage << " points of damage!" << std::endl;
		hit--;
		enegry--;
	}
	else
		std::cout <<  string << " is dead, So he can not ATTACK" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "The destroucter of ScavClap is called" << std::endl;
}
