/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:42:00 by abouzanb          #+#    #+#             */
/*   Updated: 2023/06/21 00:40:01 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

#include <cmath>
class Fixed {
	private:
		int fixed_value;
		static const int fractional = 8;
	public :
		Fixed();
		Fixed(const Fixed &f);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		~Fixed();
		Fixed &operator=(const Fixed &f);
		Fixed(const int i);
		Fixed(const float f);
		float toFloat( void ) const;
		int toInt( void ) const;		
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);


#endif