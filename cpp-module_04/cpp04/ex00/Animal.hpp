/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:09:52 by abouzanb          #+#    #+#             */
/*   Updated: 2023/06/22 02:37:43 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>


class Animal {
	protected : // this is the protected part of the class it can be accessed by the class and its children
		std::string type;
	public :
	Animal();
	Animal(Animal &animal);
	virtual ~Animal(); // this is the destructor of the class it is virtual because it will be used by the children an if it is not virtual the compiler will not call the destructor of the children
	Animal &operator=(Animal &animal);

	std::string getType() const;
	virtual void  makeSound() const; // this is the function that will be used to make sound it is virtual because it will be used by the children an if it is not virtual the compiler will not call the function of the children
};



#endif