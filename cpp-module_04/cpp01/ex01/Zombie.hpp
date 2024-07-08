/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 02:26:58 by abouzanb          #+#    #+#             */
/*   Updated: 2023/06/18 23:09:57 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP

# define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Zombie{
	private :
		std::string name; // this is the name of the zombie
	public :
		Zombie(); // this is the constructor of the class	
		~Zombie(); // this is the destructor of the class 
		void	announce(void); // this is the function that will be used to announce the zombie 
		void  set_name(std::string nom); // this is the function that will be used to set the name of the zombie
}; 
Zombie* zombieHorde( int N, std::string name ); // this is the function that will be used to create a horde of zombies

#endif