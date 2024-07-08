/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:44:17 by abouzanb          #+#    #+#             */
/*   Updated: 2023/06/16 20:41:15 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP

# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB{
	private:
		std::string name; // this is the name of the human
		Weapon      *weapon; // this is the weapon of the human
	public:
		std::string get_name();	 	
		std::string get_weapon(); 
		HumanB(std::string str); 
		~HumanB();
        void attack();
        void setWeapon(Weapon &set); // this is the function that will be used to set the weapon of the human 
};

 #endif