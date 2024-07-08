#include "../includes/check_directives.hpp"

void	checkServerName(Directives &directives, std::istringstream &iss)
{
	std::string value;

	if (directives.getServerName() != "")
		throw std::runtime_error("The server_name directive already exists.");
	std::getline(iss, value);
	if (value.empty() || isOnlyWhitespaces(value))
		throw std::runtime_error("The server_name directive is empty or contains only whitespaces.");
	value = trimSpaces(value);
	if (containsWhitespace(value))
		throw std::runtime_error("The server_name directive contains whitespaces.");
	if (!(isAlphanumeric(value)) && !(isIPAddress(value)) && !(isDomainName(value)))
		throw std::runtime_error("The server_name directive is not valid.");
	directives.setServerName(value);
}

void	checkHost(Directives &directives, std::istringstream &iss)
{
	std::string value;

	if (directives.getHost() != "")
		throw std::runtime_error("The host directive already exists.");
	std::getline(iss, value);
	if (value.empty() || isOnlyWhitespaces(value))
		throw std::runtime_error("The host directive is empty or contains only whitespaces.");
	value = trimSpaces(value);
	if (containsWhitespace(value))
		throw std::runtime_error("The host directive contains whitespaces.");
	if (!(isIPAddress(value)))
		throw std::runtime_error("The host directive is not valid.");
	directives.setHost(value);
}

void	checkListen(Directives &directives, std::istringstream &iss)
{
	std::string value;
	
	if (directives.getListen() != -1)
		throw std::runtime_error("The listen directive already exists.");
	std::getline(iss, value);
	if (value.empty() || isOnlyWhitespaces(value))
		throw std::runtime_error("The listen directive value is empty or contains only whitespaces.");
	value = trimSpaces(value);
	if (containsWhitespace(value))
		throw std::runtime_error("The listen value contains whitespaces.");
	if (!isNum(value))
		throw std::runtime_error("The listen port is not a valid positive number.");
	else if (!(atoi(value.c_str()) >= 0 && atoi(value.c_str()) <= 65535))
		throw std::runtime_error("The listen port range is not a valid.");
	directives.setListen(atoi(value.c_str()));
}

void	checkRoot(Directives &directives, std::istringstream &iss)
{
	std::string path;

	if (directives.getRoot() != "")
		throw std::runtime_error("The root directive already exists.");
	std::getline(iss, path);
	if (path.empty() || isOnlyWhitespaces(path))
		throw std::runtime_error("The root path is empty or contains only whitespaces.");
	path = trimSpaces(path);
	if (containsWhitespace(path))
		throw std::runtime_error("The root path contains whitespaces.");
	if (!(isDirectory(path.c_str())))
		throw std::runtime_error("The root folder doesn't exist.");
	directives.setRoot(path);
}

void	checkIndex(Directives &directives, std::istringstream &iss)
{
	std::string index;

	if (!(directives.getIndex().empty()))
		throw std::runtime_error("The index directive already exists.");
	while (std::getline(iss, index, ' '))
	{
		if (!(isOnlyWhitespaces(index)) && !(index.empty()))
		{
			index = trimSpaces(index);
			directives.setIndex(index);
		}
	}
	if (directives.getIndex().empty())
		throw std::runtime_error("The index directive is empty or contains only whitespaces.");
}

void	checkMaxBodySize(Directives &directives, std::istringstream &iss)
{
	std::string size;

	if (directives.getMaxBodySizeInBytes() != -1)
		throw std::runtime_error("The client max body size directive already exists.");
	std::getline(iss, size);
	if (size.empty() || isOnlyWhitespaces(size))
		throw std::runtime_error("The client max body size is empty or contains only whitespaces.");
	size = trimSpaces(size);
	if (containsWhitespace(size))
		throw std::runtime_error("The client max body size contains whitespaces.");
	std::string numericPart = size;
	std::string suffix;
    size_t suffixPos = numericPart.find_first_not_of("0123456789");
    if (suffixPos != std::string::npos)
	{
		suffix = numericPart.substr(suffixPos);
        numericPart = numericPart.substr(0, suffixPos);
		if (numericPart == "")
			throw std::runtime_error("The max body size is not valid.");
		if (suffix == "K" || suffix == "KB")
			directives.setMaxBodySizeInBytes(atoi(numericPart.c_str()) * 1024);
		else if (suffix == "M" || suffix == "MB")
			directives.setMaxBodySizeInBytes(atoi(numericPart.c_str()) * 1024 * 1024);
		else if (suffix == "G" || suffix == "GB")
			directives.setMaxBodySizeInBytes(atoi(numericPart.c_str()) * 1024 * 1024 * 1024);
		else
			throw std::runtime_error("The max body size suffix is not valid.");
	}
	else
		directives.setMaxBodySizeInBytes(atoi(numericPart.c_str()));
}

void	checkErrorPages(Directives &directives, std::istringstream &iss)
{
	std::string value;

	std::getline(iss, value);
	if (value.empty() || isOnlyWhitespaces(value))
		throw std::runtime_error("The error_page directive value is empty or contains only whitespaces.");
	value = trimSpaces(value);
	std::vector<std::string> result;
	splitString(value, result);
	if (result.size() != 2)
		throw std::runtime_error("The error_page directive syntax is invalid.");
	else if (!isNum(result[0]))
		throw std::runtime_error("The error_page status code is not valid.");
	else if (atoi(result[0].c_str()) < 100 || atoi(result[0].c_str()) > 599)
		throw std::runtime_error("The error_page status code range is not valid.");
	else if (access(result[1].c_str(), F_OK) != 0)
		throw std::runtime_error("The error_page file doesn't exist.");
	else if (access(result[1].c_str(), R_OK) != 0)
		throw std::runtime_error("The error_page file is not readable.");
	directives.setErrorPage(result[0], result[1]);
}

void	checkAutoIndex(Directives &directives, std::istringstream &iss)
{
	std::string value;

	if (directives.getAutoIndex())
		throw std::runtime_error("The autoindex directive already exists.");
	std::getline(iss, value);
	if (value.empty() || isOnlyWhitespaces(value))
		throw std::runtime_error("The autoindex directive is empty or contains only whitespaces.");
	value = trimSpaces(value);
	if (containsWhitespace(value))
		throw std::runtime_error("The autoindex value contains whitespaces.");
	if (value == "on" || value == "ON")
		directives.setAutoIndex(true);
	else if (value == "off" || value == "OFF")
		directives.setAutoIndex(false);
	else
		throw std::runtime_error("The autoindex value is not valid.");
}
