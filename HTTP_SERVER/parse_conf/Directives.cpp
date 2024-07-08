#include "../includes/Directives.hpp"

Directives::Directives() 
{
	this->serverName = "";
	this->host = "";
	this->listen = -1;
	this->errorPages["400"] = "default_error_pages/400.html";
	this->errorPages["401"] = "default_error_pages/401.html";
	this->errorPages["403"] = "default_error_pages/403.html";
	this->errorPages["404"] = "default_error_pages/404.html";
	this->errorPages["405"] = "default_error_pages/405.html";
	this->errorPages["413"] = "default_error_pages/413.html";
	this->errorPages["500"] = "default_error_pages/500.html";
	this->errorPages["503"] = "default_error_pages/503.html";
	this->maxBodySizeInBytes = -1;
	this->index.clear();
	this->root = "";
	this->autoIndex = false;
	this->locationsVec.clear();
}

Directives::Directives(const Directives& other)
{
	(*this) = other;
}

Directives&	Directives::operator=(const Directives &other)
{
	if (this != &other)
	{
		this->serverName = other.serverName;
		this->host = other.host;
		this->listen = other.listen;
		this->errorPages = other.errorPages;
		this->maxBodySizeInBytes = other.maxBodySizeInBytes;
		this->index = other.index;
		this->root = other.root;
		this->autoIndex = other.autoIndex;
		this->locationsVec = other.locationsVec;
	}
	return (*this);
}

std::string	Directives::getServerName() const
{
	return (this->serverName);
}

std::string	Directives::getHost() const
{
	return (this->host);
}

int	Directives::getListen() const
{
	return (this->listen);
}

std::map<std::string, std::string>	Directives::getErrorPages() const
{
	return (this->errorPages);
}

int	Directives::getMaxBodySizeInBytes() const
{
	return (this->maxBodySizeInBytes);
}

std::vector<std::string> Directives::getIndex() const
{
	return (this->index);
}

std::string	Directives::getRoot() const
{
	return (this->root);
}

bool	Directives::getAutoIndex() const
{
	return (this->autoIndex);
}

std::vector<Locations>	Directives::getLocationsVec() const
{
	return (this->locationsVec);
}

void	Directives::setServerName(const std::string& serverName)
{
	this->serverName = serverName;
}

void	Directives::setHost(const std::string& host)
{
	this->host = host;
}

void	Directives::setListen(const int& port)
{
    this->listen = port;
}

void	Directives::setErrorPage(const std::string& errorCode, const std::string& page)
{
    this->errorPages[errorCode] = page;
}

void	Directives::setMaxBodySizeInBytes(const int& maxBodySizeInBytes)
{
	this->maxBodySizeInBytes = maxBodySizeInBytes;
}

void	Directives::setIndex(const std::string& index)
{
	this->index.push_back(index);
}

void	Directives::setRoot(const std::string& root)
{
	this->root = root;
}

void	Directives::setAutoIndex(const bool& autoIndex)
{
	this->autoIndex = autoIndex;
}

void	Directives::setLocation(const Locations& location)
{
	this->locationsVec.push_back(location);
}
