/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:22:28 by abouzanb          #+#    #+#             */
/*   Updated: 2023/03/17 14:25:54 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

std::string	Contact::get_first_name() 
{
	return (first_name);
}

std::string	Contact::get_the_second()
{
	return (last_name);
}

std::string	Contact::get_the_nickname()
{
	return (nickname);
}

std::string	Contact::get_phone()
{
	return (phone_number);
}

std::string	Contact::get_secrete()
{
	return (darkest_secrete);
}

void	Contact::set_second_name(std::string name)
{
	last_name = name;
}

void	Contact::set_first_name(std::string name)
{
	first_name = name;
}

void	Contact::set_nickname_name(std::string name)
{
	nickname = name;
}

void	Contact::set_phone_number(std::string name)
{
	phone_number = name;
}
void	Contact::set_secrete(std::string name)
{
	darkest_secrete = name; 
}
