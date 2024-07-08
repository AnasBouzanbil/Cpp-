/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:22:37 by abouzanb          #+#    #+#             */
/*   Updated: 2023/05/19 16:34:46 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char *argv[])
{
	char	i;
	int		x = 1;
	int		y;
	if (argc == 1)
	{
		std::cout << "HEY YOU HAVE TO WRITE SOMETING. YOU CAN  TYR THIS EXAMPLE : \n\t./megaphone this letter is lower but it will be UPPER\n" ;
		return (0);
	}
	while (argv[x])
	{
		y = 0;
		while (argv[x][y])
		{
			i = argv[x][y];
			if (i >= 97 && i <= 122)
				i = i - 32;
			std::cout << i ;
			y++;
		}
		std::cout << ' ' ;
		x++;
	}
	std::cout << '\n' ;
	return (0);
}
