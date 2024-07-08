/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:50:33 by abouzanb          #+#    #+#             */
/*   Updated: 2023/06/16 20:41:01 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP

# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA{
	private:
		std::string name; // this is the name of the human
		Weapon& weapon; // this is the weapon of the human
	public:
		std::string get_name();	 // this is the function that will be used to get the name of the human 
		std::string get_weapon(); // this is the function that will be used to get the weapon of the human
		HumanA(std::string str, Weapon& weapon); // this is the constructor of the class
		~HumanA(); // this is the destructor of the class
        void attack(); // this is the function that will be used to attack
};


#endif