#ifndef SERVERS_HPP
#define SERVERS_HPP

#include <iostream>
#include <vector>
#include "Directives.hpp"

class Servers
{
	private:
		std::vector<Directives>	serversVec;

	public:
		Servers();

		std::vector<Directives>	getServersVec() const;
		
		void setServer(const Directives& server);
};

#endif