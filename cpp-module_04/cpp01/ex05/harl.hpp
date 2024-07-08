
#ifndef HARL_HPP

# define HARL_HPP

#include <fstream>
#include <iostream>
#include <string>

class Harl{
	private :
		void debug(void); // this is the function that will be used to print the debug message
		void info(void); 	// this is the function that will be used to print the info message
		void warning(void); // this is the function that will be used to print the warning message
		void error(void); // this is the function that will be used to print the error message
	public:
		void complain(std::string level); // this is the function that will be used to print the message

};


#endif
