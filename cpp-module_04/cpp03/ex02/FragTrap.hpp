/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:45:53 by abouzanb          #+#    #+#             */
/*   Updated: 2023/06/21 22:54:57 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : public ClapTrap // this is the class that will be used to create a FragTrap and it inherits from ClapTrap
{
    public:
        void highFivesGuys(void); // this is the function that will be used to give high fives
        FragTrap(std::string nn);
        FragTrap(FragTrap& copy);
        void attack(const std::string& target);
        FragTrap& operator=(FragTrap& copy);
        FragTrap(); 
        ~FragTrap();
};



#endif