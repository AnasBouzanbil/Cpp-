/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:44:43 by abouzanb          #+#    #+#             */
/*   Updated: 2023/06/23 20:41:20 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"


Cat::Cat()
{
	std::cout << "Cat constructor called" << std::endl;
	type = "Cat";
}

Cat::Cat(Cat& cat) : Animal(cat)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(Cat& cat)
{
	std::cout << "Cat assignation operator called" << std::endl;
	type = cat.getType();
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Mewoow Mewoow" << std::endl;
}


