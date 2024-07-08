#include "../includes/Servers.hpp"

Servers::Servers()
{
	this->serversVec.clear();
}

std::vector<Directives>	Servers::getServersVec() const
{
	return (this->serversVec);
}

void	Servers::setServer(const Directives& server)
{
	this->serversVec.push_back(server);
}
