#ifndef DIRECTIVES_HPP
#define DIRECTIVES_HPP

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "Locations.hpp"

class Directives
{
	private:
		std::string							serverName;
		std::string							host;
		int									listen;
		std::map<std::string, std::string>	errorPages;
		int									maxBodySizeInBytes;
		std::vector<std::string>			index;
		std::string							root;
		bool								autoIndex;
		std::vector<Locations>				locationsVec;

	public:
		Directives();
		Directives(const Directives& other);
		Directives&			operator=(const Directives& other);

		std::string							getServerName() const;
		std::string							getHost() const;
		int									getListen() const;
		std::map<std::string, std::string>	getErrorPages() const;
		int									getMaxBodySizeInBytes() const;
		std::vector<std::string>			getIndex() const;
		std::string							getRoot() const;
		bool								getAutoIndex() const;
		std::vector<Locations>				getLocationsVec() const;
		
		void	setServerName(const std::string& serverName);
		void	setHost(const std::string& host);
		void	setListen(const int& port);
		void	setErrorPage(const std::string& errorCode, const std::string& page);
		void	setMaxBodySizeInBytes(const int& maxBodySizeInBytes);
		void	setIndex(const std::string& index);
		void	setRoot(const std::string& root);
		void	setAutoIndex(const bool& autoIndex);
		void	setLocation(const Locations& location);
};

#endif