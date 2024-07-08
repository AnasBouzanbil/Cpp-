/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:49:55 by abouzanb          #+#    #+#             */
/*   Updated: 2023/03/29 23:25:23 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>
#include <string>
#include <iomanip>

class Weapon {
	private:
		std::string type;
	public:
		std::string getType();
		void setType(std::string name);
        Weapon(std::string ty);
};

#endif

