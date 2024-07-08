/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 03:21:15 by abouzanb          #+#    #+#             */
/*   Updated: 2023/06/18 23:11:44 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int i = 0;
	Zombie *a = zombieHorde(4, "Anas"); // I create an array of zombies
	std::cout << "-----------------------------------" << std::endl;
	while (i < 4) 
	{
		a[i].announce(); // I announce each zombie
		i++;
	}
	std::cout << "-----------------------------------" << std::endl;
	delete[] a; // I delete the array of zombies and each zombie will be destroyed
}