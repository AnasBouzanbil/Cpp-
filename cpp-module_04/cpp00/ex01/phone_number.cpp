/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_number.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:28:44 by abouzanb          #+#    #+#             */
/*   Updated: 2023/06/05 18:21:22 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_number.hpp"
#include <stdlib.h>

int  check(std::string& s)
{
	size_t i;
	 i = 0;

	 while (i < s.length())
	 {
		if (s[i] != ' ')
			return 1;
		i++;
	 }
	 if (i == 0)
	 	return (0);
	return (0);
}

int check_number(std::string& s)
{
	size_t i;
	 i = 0;

	 while (i < s.length())
	 {
		if (isdigit(s[i]) == 0)
			return 0;
		i++;
	 }
	 if (i == 0)
	 	return (0);
	return (1);	
}

void PhoneBook::add(int i)
{
	std::string	firstnaame;
	std::string	second;
	std::string	nickname;
	std::string	number;
	std::string	secrete;

	std::cout << "\n";
	while (strlen(firstnaame.c_str()) <= 0 ||check(firstnaame) == 0) // we check if the first name is empty or if it contains only spaces
	{
		std::cout << "\e[0;30mPlease enter the first name : \e[1;30m"; 
		getline(std::cin, firstnaame);
		if (std::cin.eof()) { // if the user wants to exit by pressing ctrl + D
		exit(0); // we exit 
	}
	}
	while (strlen(second.c_str() ) <= 0 ||check(second) == 0) // we check if the second name is empty or if it contains only spaces
	{
		std::cout << "\e[0;30mPlease enter the last name : \e[1;30m";
		getline(std::cin, second);
		if (std::cin.eof()) {
			exit(0);
		}
	}
	
	while (strlen(nickname.c_str() )<= 0 ||check(nickname) == 0) 		// we check if the nickname is empty or if it contains only spaces
	{
		std::cout << "\e[0;30mPlease enter the nickname : \e[1;30m";
		getline(std::cin, nickname);
		if (std::cin.eof()) {
			exit(0);
	}
	}
	while (strlen(number.c_str() )<= 0  || check_number(number) == 0)  // we check if the phone number is empty or if it contains only spaces and if it contains only digits
	{
		std::cout << "\e[0;30mPlease enter the phone  number : \e[1;30m";
		getline(std::cin, number);
		if (std::cin.eof())
			exit(0);
	}
	while (strlen(secrete.c_str()) <= 0 ||check(secrete) == 0) // we check if the darkest secrete is empty or if it contains only spaces
	{
		std::cout << "\e[0;30mPlease enter the darkest_secrete : \e[1;30m";
		getline(std::cin, secrete);
		std::cout << "\e[0m";
		if (std::cin.eof())
			exit(0);
	}
	account[i].set_first_name(firstnaame); //  we set the first name
	account[i].set_second_name(second); // we set the second name
	account[i].set_nickname_name(nickname); // we set the nickname
	account[i].set_phone_number(number); // we set the phone number
	account[i].set_secrete(secrete); // we set the darkest secrete
}

void	print_colo()
{
	std::cout << "\n\e[1;36m" << std::endl;
	std::cout << std::setw(10) << "Index" << "|" 
				<< std::setw(10) << "First name" << "|"
				<< std::setw(10) << "Last name" << "|"
				<< std::setw(10) << "nickname" << "|";
	std::cout << "\e[1;30m\n";
}

void	PhoneBook::print()
{
	int			i;
	std::string	firstname;
	std::string	secondname;
	std::string	nickname;
	i = 0; 
	print_colo(); // we print the header of the table
	while (i < size) // we loop until the size of the phonebook
	{
		firstname = account[i].get_first_name(); // we get the first name
		secondname = account[i].get_the_second(); // we get the second name
		nickname = account[i].get_the_nickname(); // we get the nickname
		if (strlen(firstname.c_str()) >= 10) // if the length of the first name is greater than 10
		{
			firstname = firstname.substr(0, 9); // we get the first 9 characters
			firstname += "."; // and we add three dots
		}

		if (strlen(secondname.c_str())	>= 10) // if the length of the second name is greater than 10
		{
			secondname = secondname.substr(0, 9); // we get the first 9 characters
			secondname += "."; // and we add three dots
		}

		if (strlen(nickname.c_str())  >= 10) // if the length of the nickname is greater than 10
		{
			nickname = nickname.substr(0, 9); // we get the first 9 characters
			nickname += "."; // and we add three dots
		}

		std::cout   << std::setw(10) << i  << "|" // setw is used to set the width of the string
					<< std::setw(10) << firstname  << "|" // we use setw to make the table
					<< std::setw(10) << secondname  << "|" // we use setw to make the table
					<< std::setw(10) << nickname << "|\n"; // we use setw to make the table
		i++; 
	}
	std::cout << "\n";
}

void	PhoneBook::print_index(int	i)
{
	std::cout << "\n";
	std::cout << "Index       : " << i << std::endl;
	std::cout << "First name  : " << account[i].get_first_name() << std::endl;
	std::cout << "Second name : " << account[i].get_the_second() << std::endl;
	std::cout << "Nickname    : " << account[i].get_the_nickname() << std::endl;
	std::cout << "\n";
}

int	check_is_digit(std::string str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	PhoneBook::search() 
{
	int	i;

	i = 0;
	std::string numstr;  
	if (size == 0)  // if there is no contact
	{
		std::cout << "\e[0;33m\tUnfortunately there is no contact until now\e[0m" <<  std::endl;
		return; 
	}
	print(); // we print the phonebook
	std::cout << "please choose an index : ";
	getline(std::cin, numstr); // we get the index
	if (std::cin.eof()) // if the user wants to exit by pressing ctrl + D
		exit(0);
	if (check_is_digit(numstr) == 1) // if the index is not a digit
	{
		std::cout << "\e[0;31m the index that you entered is not a digit\e[0m\n";
		return ; // we return
	}
	i = std::atoi(numstr.c_str()); // we convert the index to an integer
	if (i >= size || i < 0) // if the index is out of range
	{
		std::cout << "\e[0;31m the index that you entered isout of range of contact\e[0m\n";
		return ; // we return
	}
	print_index(i); // we print the contact
}
