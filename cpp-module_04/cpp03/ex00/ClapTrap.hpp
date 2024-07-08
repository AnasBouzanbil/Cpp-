/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:41:43 by abouzanb          #+#    #+#             */
/*   Updated: 2023/06/21 19:52:16 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string string; // this is the name of the ClapTrap 
		int hit; // this is the hit point of the ClapTrap 
		int enegry;
		int damage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap& newe);
		ClapTrap& operator=(ClapTrap& newe);
		~ClapTrap();
		void attack(const std::string& target); // this is the function that will be used to attack
		void takeDamage(unsigned int amount); // this is the function that will be used to take damage 
		void beRepaired(unsigned int amount); // this is the function that will be used to be repaired
};

#endif