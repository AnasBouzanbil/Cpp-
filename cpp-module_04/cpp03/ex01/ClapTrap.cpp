/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:41:37 by abouzanb          #+#    #+#             */
/*   Updated: 2023/06/21 23:41:44 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "\e[0;32mClapTrap constructor called\e[0m" << std::endl;
	hit		=	10;
	enegry	=	10;
	damage	=	0;
}
ClapTrap::ClapTrap(std::string name)
{
	std::cout << "\e[0;32mClapTrap parametred constructor called\e[0m" << std::endl;
	string	=	name;
	hit		=	10;
	enegry	=	10;
	damage	=	0;
}
ClapTrap::ClapTrap(ClapTrap& newe)
{
	std::cout << "\e[0;32mClapTrap copy constructor called\e[0m" << std::endl;
	hit		=	newe.hit;
	string	=	newe.string;
	enegry	=	newe.enegry;
	damage	=	newe.damage;
}
ClapTrap& ClapTrap::operator=(ClapTrap& newe)
{
	std::cout << "\e[0;32mClapTrap operator= called\e[0m" << std::endl;
	hit		=	newe.hit;
	string	=	newe.string;
	enegry	=	newe.enegry;
	damage	=	newe.damage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "\e[0;31mClapTrap destructor called\e[0m" << std::endl;
}
void ClapTrap::attack(const std::string& target)
{
	if (hit > 0 && enegry > 0)
	{
		std::cout << "ClapTrap : " << string << " attack " << target << ", causing " << damage << " points of damage!" << std::endl;
		hit--;
		enegry--;
	}
	else 
		std::cout << "\e[0;32m"<< string << " is already dead and he can not attack\e[0m" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit > 0 && enegry > 0)
	{
		std::cout << string << " got " << amount << " point of damage" << std::endl;
		hit -= amount;
		enegry--;
	}
	else 
		std::cout << string << " is already dead" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hit < 0 || enegry <= 0)
		 std::cout << string << " is dead and cannot be repaired" << std::endl;
	else {
		std::cout <<string << " got " << amount << " of hit point" << std::endl;
		hit += amount;
		if (hit > 10)
			hit = 10;
		enegry--;
	}
}