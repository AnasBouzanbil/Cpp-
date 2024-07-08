/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:56:56 by abouzanb          #+#    #+#             */
/*   Updated: 2023/06/22 02:37:30 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"

void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}
 
std::string Animal::getType() const
{
	return (type);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(Animal &animal)
{
	std::cout << "Animal copy constructor called" << std::endl;
	type = animal.getType();
}

Animal& Animal::operator=(Animal &animal)
{
	std::cout << "Animal assignation operator called" << std::endl;
	return (animal);
}
Animal::Animal()
{
	std::cout << "Animal constructor called" << std::endl;
	type = "Animal";
}
