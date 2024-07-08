/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 22:17:49 by abouzanb          #+#    #+#             */
/*   Updated: 2023/06/18 22:52:56 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	if (ac != 4) // if the number of arguments is not 4
	{
		std::cout << "\033[1;31mError: \033[0m" << "Wrong number of arguments \n You have to put them like : ./sed FILENAME replaced to_be_replaced_by" << std::endl;
		return (1); // we return 1
	}
	std::ifstream ifs(av[1]); // we open the file in read mode 
	if (!ifs.is_open()) // if the file is not open
	{
		std::cout << "\033[1;31mError: \033[0m" << "File does not exist" << std::endl;
		return (1); // we return 1
	}
	std::ofstream ofs(av[1] + std::string(".replace")); // we open the file in write mode 
	if (!ofs.is_open()) // if the file is not open
	{
		std::cout << "\033[1;31mError: \033[0m" << "File does not exist" << std::endl;
		return (1); // we return 1
	}
	std::string readed; // we create a string to read the file
	std::string replaced; // we create a string to replace the string
	std::string to_replace = av[2];	// we create a string to replace the string 
	std::string replace_by = av[3]; // we create a string to replace the string 
	int pos = 0; // we create a variable to store the position of the string
	size_t found; // we create a variable to store the position of the string
	while (std::getline(ifs, readed)) // while we can read the file
	{
		pos = 0; 
		if (av[2][0] != '\0') // if the string to replace is not empty 
		{ 
			while (true) // while we can find the string to replace
			{
				found = readed.find(to_replace, pos);  // we search the string to replace
				if (found == std::string::npos) // if we can't find the string to replace
					break;    // we break the loop
				replaced = readed.substr(0, found); // we store the string before the string to replace
				replaced += replace_by; // we store the string to replace by
				pos = replaced.length();   // we store the length of the string to replace by
				replaced += readed.substr(found + to_replace.length()); // we store the string after the string to replace
				readed = replaced; // we store the string replaced
			}
		}
		ofs << readed << std::endl; // we write the string in the file 
	} 

	std::cout << "\033[1;32mSuccess: \033[0m" << "File successfully replaced" << std::endl;
	return (0);
}