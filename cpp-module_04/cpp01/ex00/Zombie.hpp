/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:54:45 by abouzanb          #+#    #+#             */
/*   Updated: 2023/03/25 20:32:08 by abouzanb        ###   ########.fr       */
/*                                        		                              */
/* ************************************************************************** */


#ifndef ZOMBIE_HPP

# define ZOMBIE_HPP


#include <iostream>
#include <string>
#include <iomanip>



class Zombie {
	private :
		std::string name; // this is the name of the zombie
	public :
		Zombie(std::string nom); // this is the constructor of the class
		~Zombie(); // this is the destructor of the class 
		void	announce(void); // this is the function that will be used to announce the zombie
};
Zombie* newZombie( std::string name ); // this is the function that will be used to create a new zombie
void	randomChump( std::string name ); // this is the function that will be used to create a random zombie

#endif