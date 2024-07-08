

#include <iostream>

class Bureaucrat
{
    private:
        std::string const name;
        int grade;
    public:
    int getgrade();
    std::string getname();
    void setgrade(int grade);
    void setname(std::string name);
};

int Bureaucrat::getgrade()
{
    return (grade);
}

std::string Bureaucrat::getname()
{
    return (name);
}

void Bureaucrat::setgrade(int grade)
{
}


