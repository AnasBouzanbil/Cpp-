/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 01:54:06 by abouzanb          #+#    #+#             */
/*   Updated: 2023/06/16 02:44:44 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl{
    private:
        std::string name;
    public:
        Harl(std::string name);
        ~Harl();
        void debug();
        void error();
        void info();
        void warning();
        std::string get_name();
        void set_name(std::string name);
};










#endif


