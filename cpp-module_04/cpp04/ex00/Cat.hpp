#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal // thsi class will inherit from Animal class
{
    public:
        Cat();
        Cat(Cat& cat);
        ~Cat(); 
        Cat& operator=(Cat& cat);
        void makeSound() const;  // this is the function that will be used to make sound and it will be overriden to print the right message
};

#endif      