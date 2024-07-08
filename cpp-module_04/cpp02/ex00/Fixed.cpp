/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 00:51:11 by abouzanb          #+#    #+#             */
/*   Updated: 2023/06/21 00:51:12 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout  << "Default constructor called" << std::endl;
    fixedpoint = 0;
}

Fixed::~Fixed() {
    std::cout  << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
    std::cout  << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
    std::cout  << "Assignation operator called" << std::endl;
    if (this != &fixed)
        fixedpoint = fixed.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const {
    std::cout  << "getRawBits member function called" << std::endl;
    return fixedpoint;
}

void Fixed::setRawBits(int const raw) {
    std::cout  << "setRawBits member function called" << std::endl;
    fixedpoint = raw;
}
