/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:22:15 by abouzanb          #+#    #+#             */
/*   Updated: 2023/04/19 17:59:58 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_number.hpp"
int	 main()
{
	std::string	str;
	PhoneBook	my_contact;
	int			i;

	i = 0;
	my_contact.size = 0;
	while (1) // we loop until the user wants to exit
	{

		std::cout << "please enter a choice  : "; // we ask the user to enter a choice
		std::getline(std::cin, str); // we get the choice of the user
		if (std::cin.eof()) // if the user wants to exit by pressing ctrl + D
			exit(0);
		if (str == "ADD") // if the user wants to add a contact
		{		
			if (i == 7) // if the phonebook is full
			i = 0; // we start from the beginning
			my_contact.add(i); // we add a contact
			if (my_contact.size == 7) // if the phonebook is full
				my_contact.size = 7; // we don't increment the size
			else  // if the phonebook is not full
				my_contact.size++; // we increment the size
				i++; 
		}
		else if (str == "SEARCH") // if the user wants to search a contact
			my_contact.search(); // we search a contact
		else if (str == "EXIT") // if the user wants to exit
			exit(0); // we exit
	}
}