/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_number.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 00:36:46 by abouzanb          #+#    #+#             */
/*   Updated: 2023/05/16 20:11:40 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

class PhoneBook{
	//this is the class that will be used to create the phonebook
		Contact account[8];
	public:
		int size; // this is the size of the phonebook
		void add(int i); // this is the function that will be used to add a contact
		void print_index(int i); // this is the function that will be used to print a contact
		void search(); // this is the function that will be used to search a contact
		void print(); // this is the function that will be used to print the phonebook
		//thos function are called member functions
};
