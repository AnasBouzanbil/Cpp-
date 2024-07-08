/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:09:52 by abouzanb          #+#    #+#             */
/*   Updated: 2023/06/23 20:09:12 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"


class Animal {
	protected :
		std::string type;
	public :
	Animal();
	Animal(Animal &animal);
	virtual ~Animal();
	Animal &operator=(Animal &animal);
	std::string getType() const;
	virtual void  makeSound() const = 0;
};


#endif