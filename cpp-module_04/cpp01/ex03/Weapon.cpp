/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:05:08 by abouzanb          #+#    #+#             */
/*   Updated: 2023/05/18 23:42:53 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Weapon.hpp"

std::string Weapon::getType()
{
	return (type);
}

void Weapon::setType(std::string str)
{
	type = str;
}
Weapon::Weapon(const std::string ty)
{
    type = ty;
}