/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 02:51:59 by abouzanb          #+#    #+#             */
/*   Updated: 2023/03/26 03:39:20 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	int	i;

	i = 0;
	Zombie	*zombie = new Zombie[N]; // I create an array of zombies
	while(i < N) // I set the name of each zombie
	{ 
		zombie[i].set_name(name); // I set the name of the zombie
		i++; 
	}
	return (zombie); // I return the array of zombies
} 