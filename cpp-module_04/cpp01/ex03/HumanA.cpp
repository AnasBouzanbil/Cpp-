/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 03:03:19 by abouzanb          #+#    #+#             */
/*   Updated: 2023/03/30 16:35:05 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

std::string HumanA::get_name()
{
	return (name);
}

std::string HumanA::get_weapon()
{
	return (weapon.getType());
}

HumanA::HumanA(std::string str, Weapon& weap) : weapon(weap) // this is the constructor of the class HumanA 
{
	name  = str;
}

HumanA::~HumanA()
{
	
}

void HumanA::attack()
{
   std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
