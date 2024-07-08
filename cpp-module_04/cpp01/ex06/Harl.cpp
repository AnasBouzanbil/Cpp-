/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:57:50 by abouzanb          #+#    #+#             */
/*   Updated: 2023/06/18 23:03:18 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"

Harl::Harl(std::string name){
  //  std::cout << "Harl " << name << " is born" << std::endl;
        this->name = name;
}

Harl::~Harl(){
  //  std::cout << "Harl " << this->name << " is dead" << std::endl;
}


void Harl::debug(){
    std::cout << "[DEBUG]  \n" << "I should probably have asked for a sick day today" << std::endl;
}

void Harl::error(){
    std::cout << "[ERROR]  \n " << "I am sorry to tell you that you are not allowed to do that you have to fix the Error" << std::endl;
}

void Harl::info(){
    std::cout << "[INFO]  \n" << "I am a Harl. did you know it" << std::endl;
}

void Harl::warning(){
    std::cout << "[WARNING]  \n" << "I think I deserve to have some extra bacon for free. \nI've been coming for years whereas you started working here since last month" << std::endl;
}
std::string Harl::get_name(){
    return this->name;
}

void Harl::set_name(std::string name){
    this->name = name;
}
