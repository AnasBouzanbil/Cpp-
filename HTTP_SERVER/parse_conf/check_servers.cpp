#include "../includes/check_servers.hpp"

void	parse_servers(Servers &servers)
{
	std::vector<Directives>	serversVec = servers.getServersVec();
	size_t serversSize = serversVec.size();

	for (size_t i = 0; i < serversSize; i++) {
		if (serversVec[i].getServerName() == "")
			serversVec[i].setServerName("localhost");
		if (serversVec[i].getHost() == "")
			throw std::runtime_error("The host directive doesn't exist.");
		if (serversVec[i].getListen() == -1)
			throw std::runtime_error("The listen directive doesn't exist.");
		if (serversVec[i].getMaxBodySizeInBytes() == -1)
			throw std::runtime_error("The client max body size directive doesn't exist.");
		if (serversVec[i].getRoot() == "")
			throw std::runtime_error("The root directive doesn't exist.");
		if (serversVec[i].getLocationsVec().empty())
			throw std::runtime_error("No location directive exist in the server block.");
		else
		{
			std::vector<Locations>	locationsVec = serversVec[i].getLocationsVec();
			size_t locationsSize = locationsVec.size();
			for (size_t j = 0; j < locationsSize; j++) {
				if (locationsVec[j].getLocation() == "")
					throw std::runtime_error("The location directive syntax is invalid.");
				else if (locationsVec[j].getRoot() == "")
					throw std::runtime_error("The location directive root doesn't exist.");
				else if (locationsVec[j].getAcceptedMethods()["POST"] == false && \
						locationsVec[j].getAcceptedMethods()["GET"] == false && \
						locationsVec[j].getAcceptedMethods()["DELETE"] == false)
					throw std::runtime_error("The location accepted methods directive doesn't exist.");
			}
		}
	}

	for (size_t i = 0; i < serversSize; i++) {
		size_t j = i + 1;
		while (j < serversSize)
		{
			if (serversVec[i].getServerName() == serversVec[j].getServerName())
			{
				if (serversVec[i].getHost() == serversVec[j].getHost())
				{
					if (serversVec[i].getListen() == serversVec[j].getListen())
						throw std::runtime_error("The server_name, host and port of two different server blocks are identical.");
				}
			}
			j++;
		}
	}
}
