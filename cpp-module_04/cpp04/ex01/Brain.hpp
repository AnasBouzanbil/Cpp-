

#ifndef BRAIN_HPP

# define BRAIN_HPP

# include <iostream>

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		~Brain();
		Brain(Brain &brain);
		Brain& operator=(Brain &brain);
		void set_ideas(std::string idea, int index);
		std::string get_ideas(int index) const;
};



#endif