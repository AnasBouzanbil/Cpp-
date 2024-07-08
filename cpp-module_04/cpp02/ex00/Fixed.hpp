#ifndef FIXED_HPP

#define FIXED_HPP

#include <iostream>
class Fixed { // this is the class that will be used to create fixed point values
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &fixed);
        Fixed &operator=(const Fixed &fixed);
        int getRawBits(void) const; // this is the function that will be used to get the raw bits   
        void setRawBits(int const raw); // this is the function that will be used to set the raw bits
    private:
        int fixedpoint;  // this is the fixed point value
        static const int bits = 8; // this is the number of fractional bits
};

#endif