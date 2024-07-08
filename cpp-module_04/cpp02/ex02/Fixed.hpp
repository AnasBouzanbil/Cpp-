

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
		Fixed operator+(const Fixed &f) const;
		Fixed operator-(const Fixed &f) const;
		Fixed operator*(const Fixed &f) const;
		Fixed operator/(const Fixed &f) const;
		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);
		bool operator>(const Fixed &f) const;
		bool operator<(const Fixed &f) const;
		bool operator>=(const Fixed &f) const;
		bool operator<=(const Fixed &f) const;
		bool operator==(const Fixed &f) const;
		bool operator!=(const Fixed &f) const;
		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);

};

std::ostream &operator<<(std::ostream &out, Fixed const &value);

