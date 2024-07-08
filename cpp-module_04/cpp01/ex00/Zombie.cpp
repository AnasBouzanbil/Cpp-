/* ************************************************************************** */
/*																			  */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+	+#+           */
/*   Created: 2023/03/25 18:44:43 by abouzanb          #+#	  #+#             */
/*   Updated: 2023/03/25 18:47:28 by abouzanb         ###	########.fr       */
/*									                                     	  */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::~Zombie()
{
	std::cout << "Destructor called now, name is " << name << std::endl;
}

Zombie::Zombie(std::string nom)
{
	name = nom; // we assign the name of the zombie
}
void Zombie::announce(void)
{
	std::cout << name ;// we print the name of the zombie
	std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl; 
}
