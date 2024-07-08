#include "Fixed.hpp"

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

bool Fixed::operator>(const Fixed &f) const
{
	return (this->getRawBits() > f.getRawBits());
}

bool Fixed::operator<(const Fixed &f) const
{
	return (this->getRawBits() < f.getRawBits());
}

bool Fixed::operator>=(const Fixed &f) const
{
	return (this->getRawBits() >= f.getRawBits());
}

bool Fixed::operator<=(const Fixed &f) const
{
	return (this->getRawBits() <= f.getRawBits());
}

bool Fixed::operator==(const Fixed &f) const
{
	return (this->getRawBits() == f.getRawBits());
}

bool Fixed::operator!=(const Fixed &f) const
{
	return (this->getRawBits() != f.getRawBits());
}

Fixed &Fixed::operator++(void)
{
	this->fixed_value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->fixed_value++;
	return (tmp);
}

Fixed &Fixed::operator--(void)
{
	this->fixed_value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->fixed_value--;
	return (tmp);
}

Fixed Fixed::operator*(const Fixed &f) const
{
	Fixed tmp;
	tmp.setRawBits((this->getRawBits() * f.getRawBits()) / 256);
	return (tmp);
}

Fixed Fixed::operator/(const Fixed &f) const
{
	Fixed tmp;
	tmp.setRawBits((this->getRawBits() / f.getRawBits()) * 256);
	return (tmp);
}


Fixed Fixed::operator+(const Fixed &f) const
{
	Fixed tmp;
	tmp.setRawBits(this->getRawBits() + f.getRawBits());
	return (tmp);
}

Fixed Fixed::operator-(const Fixed &f) const
{
	Fixed tmp;
	tmp.setRawBits(this->getRawBits() - f.getRawBits());
	return (tmp);
}

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
	*this = f;
}

Fixed::Fixed()
{
	fixed_value = 0;
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
	return fixed_value;
}

void Fixed::setRawBits(int const raw)
{
	fixed_value = raw;
}

Fixed::Fixed(const int i)
{
	fixed_value = i * 256;
}

Fixed::Fixed(const float f)
{
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
