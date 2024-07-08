/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 22:10:04 by abouzanb          #+#    #+#             */
/*   Updated: 2023/06/18 22:47:13 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	std::cout << "-----------------------------------" << std::endl;
    Zombie a("Elhazin"); // I create a zombie
	a.announce(); // I announce the zombie
	std::cout << "-----------------------------------" << std::endl;
	Zombie *b = newZombie("abouzanb"); // I create a zombie
	b->announce(); // I announce the zombie
	delete b; // I delete the zombie
	std::cout << "-----------------------------------" << std::endl;
	randomChump("abouzanb"); // I create a zombie and announce it
}
