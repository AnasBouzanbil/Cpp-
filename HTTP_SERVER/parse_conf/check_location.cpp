#include "../includes/check_location.hpp"

void	checkLocationRoot(Locations &location, std::istringstream &iss)
{
	std::string path;

	if (location.getRoot() != "")
		throw std::runtime_error("The location root directive already exists.");
	std::getline(iss, path);
	if (path.empty() || isOnlyWhitespaces(path))
		throw std::runtime_error("The location root path is empty or contains only whitespaces.");
	path = trimSpaces(path);
	if (containsWhitespace(path))
		throw std::runtime_error("The location root path contains whitespaces.");
	if (!(isDirectory(path.c_str())))
		throw std::runtime_error("The location root folder doesn't exist.");
	location.setRoot(path);
}

void	checkLocationIndex(Locations &location, std::istringstream &iss)
{
	std::string index;

	if (!(location.getIndex().empty()))
		throw std::runtime_error("The location index directive already exists.");
	while (std::getline(iss, index, ' '))
	{
		if (!(isOnlyWhitespaces(index)) && !(index.empty()))
		{
			index = trimSpaces(index);
			location.setIndex(index);
		}
	}
	if (location.getIndex().empty())
		throw std::runtime_error("The location index directive is empty or contains only whitespaces.");
}

void	checkLocationAutoIndex(Locations &location, std::istringstream &iss)
{
	std::string value;

	if (location.getAutoIndex())
		throw std::runtime_error("The location autoindex directive already exists.");
	std::getline(iss, value);
	if (value.empty() || isOnlyWhitespaces(value))
		throw std::runtime_error("The location autoindex directive is empty or contains only whitespaces.");
	value = trimSpaces(value);
	if (containsWhitespace(value))
		throw std::runtime_error("The location autoindex value contains whitespaces.");
	if (value == "on" || value == "ON")
		location.setAutoIndex(true);
	else if (value == "off" || value == "OFF")
		location.setAutoIndex(false);
	else
		throw std::runtime_error("The location autoindex value is not valid.");
}

void	checkLocationAcceptedMethods(Locations &location, std::istringstream &iss)
{
	std::string method;

	bool allValuesAreFalse = true;

	std::map<std::string, bool>myMap = location.getAcceptedMethods();
    std::map<std::string, bool>::iterator it;
    for (it = myMap.begin(); it != myMap.end(); it++)
	{
        if (it->second != false)
		{
            allValuesAreFalse = false;
            break;
        }
    }
	if (!allValuesAreFalse)
		throw std::runtime_error("The location accepted_methods directive already exists.");
	while (std::getline(iss, method, ' '))
	{
		if (!(isOnlyWhitespaces(method)) && !(method.empty()))
		{
			method = trimSpaces(method);
			if (method == "GET")
			{
				if (location.getAcceptedMethods()["GET"] == true)
					throw std::runtime_error("The GET method value is alraedy set as accepted method.");
				location.setAcceptedMethods("GET", true);
			}
			else if (method == "POST")
			{
				if (location.getAcceptedMethods()["POST"] == true)
					throw std::runtime_error("The POST method value is alraedy set as accepted method.");
				location.setAcceptedMethods("POST", true);
			}
			else if (method == "DELETE")
			{
				if (location.getAcceptedMethods()["DELETE"] == true)
					throw std::runtime_error("The DELETE method value is alraedy set as accepted method.");
				location.setAcceptedMethods("DELETE", true);
			}
			else
				throw std::runtime_error("A location accepted method value is not recognized.");
		}
	}
	if (location.getAcceptedMethods().empty())
		throw std::runtime_error("The location accepted methods directive is empty or contains only whitespaces.");
}

void	checkLocationCgi(Locations &location, std::istringstream &iss)
{
	std::string value;

	std::getline(iss, value);
	if (value.empty() || isOnlyWhitespaces(value))
		throw std::runtime_error("The location cgi directive is empty or contains only whitespaces.");
	value = trimSpaces(value);
	std::vector<std::string> result;
	splitString(value, result);
	if (result.size() != 2)
		throw std::runtime_error("The location cgi directive syntax is invalid.");
	if ((result[0] != ".py" || result[1] != "/bin/python3") && \
			(result[0] != ".php" || result[1] != "/usr/bin/php")) //here change to /usr/bin/php
		throw std::runtime_error("The location cgi directive is not valid.");
	location.setCgi(result[0], result[1]);
}

void	checkLocationCgiAllowed(Locations &location, std::istringstream &iss)
{
	std::string value;

	if (location.getCgiAllowed())
		throw std::runtime_error("The location cgi-allowed directive already exists.");
	std::getline(iss, value);
	if (value.empty() || isOnlyWhitespaces(value))
		throw std::runtime_error("The location cgi-allowed directive is empty or contains only whitespaces.");
	value = trimSpaces(value);
	if (containsWhitespace(value))
		throw std::runtime_error("The location cgi-allowed value contains whitespaces.");
	if (value == "on" || value == "ON")
		location.setCgiAllowed(true);
	else if (value == "off" || value == "OFF")
		location.setCgiAllowed(false);
	else
		throw std::runtime_error("The location cgi-allowed value is not valid.");
}

void	checkLocationReturn(Locations &location, std::istringstream &iss)
{
	std::string value;

	if (location.getReturn() != "")
		throw std::runtime_error("The location return directive already exists.");
	std::getline(iss, value);
	if (value.empty() || isOnlyWhitespaces(value))
		throw std::runtime_error("The location Return directive is empty or contains only whitespaces.");
	value = trimSpaces(value);
	if (containsWhitespace(value))
		throw std::runtime_error("The location return directive contains whitespaces.");
	location.setReturn(value);
}

void	checkLocationUploadStore(Locations &location, std::istringstream &iss)
{
	std::string path;

	if (location.getUploadStore() != "../uploads")
		throw std::runtime_error("The location upload_store directive already exists.");
	std::getline(iss, path);
	if (path.empty() || isOnlyWhitespaces(path))
		throw std::runtime_error("The location upload_store path is empty or contains only whitespaces.");
	path = trimSpaces(path);
	if (containsWhitespace(path))
		throw std::runtime_error("The location upload_store path contains whitespaces.");
	if (!(isDirectory(path.c_str())))
		throw std::runtime_error("The location upload_store folder doesn't exist.");
	location.setUploadStore(path);
}

void	checkLocation(Locations &location, std::istringstream &iss, std::string directive)
{
	if (directive == "root")
		checkLocationRoot(location, iss);
	else if (directive == "index")
		checkLocationIndex(location, iss);
	else if (directive == "autoindex")
		checkLocationAutoIndex(location, iss);
	else if (directive == "accepted_methods")
		checkLocationAcceptedMethods(location, iss);
	else if (directive == "return")
		checkLocationReturn(location, iss);
	else if (directive == "cgi-allowed")
		checkLocationCgiAllowed(location, iss);
	else if (directive == "cgi")
		checkLocationCgi(location, iss);
	else if (directive == "upload_store")
		checkLocationUploadStore(location, iss);
	else
		throw std::runtime_error("The location directive contains an unknown or unsupported directive.");
}
