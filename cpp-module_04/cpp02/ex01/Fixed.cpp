#include "Fixed.hpp"

std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
	out << value.toFloat();
	return (out);
}

Fixed &Fixed::operator=(const Fixed &f)
{
	
	this->fixed_value = f.getRawBits();
	return (*this);
}  

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fixed_value = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return fixed_value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	fixed_value = raw;
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	fixed_value = i * 256;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	fixed_value = roundf(f * 256);
}

float Fixed::toFloat( void ) const
{
   return ((float)fixed_value / 256);
}

int Fixed::toInt( void ) const
{
	return(fixed_value  / 256);
}
