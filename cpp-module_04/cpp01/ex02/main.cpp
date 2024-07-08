/* ************************************************************************** */
/*		                                                                      */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 03:43:40 by abouzanb          #+#    #+#             */
/*   Updated: 2023/06/18 22:38:54 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
int main()
{
	std::string str = "HI THIS IS BRAIN"; // I create a string
	std::string& stringREF = str; // I create a reference to the string and set it to the string
	 
	std::string *stringPTR; // I create a pointer to the string
	stringPTR = &str; // I set the pointer to the address of the string
	std::cout << &str << std::endl; // I print the address of the string
	std::cout << stringPTR << std::endl; // I print the address of the pointer
	std::cout << &stringREF << std::endl; // I print the address of the reference
	
	std::cout << str << std::endl; // I print the string
	std::cout << *stringPTR << std::endl; // I print the string
	std::cout << stringREF << std::endl; // I print the string
}

// teh reference is a variable that is an alias to another variable
// the pointer is a variable that contains the address of another variable
// the pointer is a variable
// the reference is not null
// the pointer can be null
// Th eponter can be reassigned
// the reference cannot be reassigned
// when you use a reference, you are using the original variable
// when you declare a reference, you must initialize it and you cannot change it later and you can not declare it without initialization
