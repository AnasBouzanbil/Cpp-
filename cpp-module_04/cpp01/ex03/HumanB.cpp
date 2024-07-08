/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:44:47 by abouzanb          #+#    #+#             */
/*   Updated: 2023/06/12 15:05:04 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

std::string HumanB::get_name()
{
	return (name);
}

std::string HumanB::get_weapon()
{
	return (weapon->getType());
}

HumanB::HumanB(std::string str)
{
    name = str;
}


HumanB::~HumanB()
{
    std::cout << name << " is dead\n";
}


void HumanB::setWeapon(Weapon &set)
{
    weapon = &set;
}

void HumanB::attack()
{
    if (weapon != NULL)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else 
        std::cout << name << " attacks without any weapon\n";
}