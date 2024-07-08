#include "../includes/conf_parser.hpp"

void	checkArgs(char **argv, std::ifstream &conf)
{
	if (std::string(argv[1]).rfind(".conf") != (std::string(argv[1]).length() - 5))
		throw std::invalid_argument("Invalid config file extension.");

	if (!conf.is_open())
		throw std::runtime_error("Failed to open conf file : " + std::string(argv[1]) + ".");
}

void	addServerDirectivesToServers(Directives &serverDirectives, Servers &servers)
{
	Directives	serverblock = serverDirectives;
	servers.setServer(serverblock);
}

void	addLocationDirectiveToServer(Directives &serverDirectives, Locations &location)
{
	Locations	locationBlock = location;
	serverDirectives.setLocation(locationBlock);
	location.clearLocation();
}

void	skipEmptyLinesAndCheckServerBlock(std::ifstream &conf, bool flag, Servers &servers)
{
	std::string	line;
	bool fileIsEmpty;
	
	fileIsEmpty = flag;
	while (std::getline(conf, line))
	{
		if (line.empty() || isOnlyWhitespaces(line))
			continue ;
		removeWhitespaces(line);
		if (line == "server{")
		{
			fileIsEmpty = false;
			readAndCheckConf(conf, servers);
		}
		else
			throw std::runtime_error("Invalid format in the config file.");
	}
	if (fileIsEmpty)
		throw std::runtime_error("The config file is empty.");
}

void	readAndCheckConf(std::ifstream &conf, Servers &servers)
{
	std::string	line;
	Directives	serverDirectives;
	Locations 	serverLocations;
	int			endBracketNum;
	int			startBracketNum;
	bool		serverBlockIsNotEmpty;
	bool		isLocationBlck;
	bool		locationBlockIsNotEmpty;

	startBracketNum = 1;
	endBracketNum = 0;
	serverBlockIsNotEmpty = false;
	isLocationBlck = false;
	locationBlockIsNotEmpty = false;
	while (std::getline(conf, line))
	{
		if (line.empty() || isOnlyWhitespaces(line))
			continue ;
		if (isLocationBlock(trimSpaces(line)))
		{
			isLocationBlck = true;
			startBracketNum++;
		}
		if (trimSpaces(line) == "}")
		{
			if (!serverBlockIsNotEmpty)
				throw std::runtime_error("Server block is empty.");
			if (isLocationBlck && !locationBlockIsNotEmpty)
				throw std::runtime_error("location block is empty.");
			if (isLocationBlck && locationBlockIsNotEmpty)
				addLocationDirectiveToServer(serverDirectives, serverLocations);
			isLocationBlck = false;
			locationBlockIsNotEmpty = false;
			endBracketNum++;
			if (startBracketNum == endBracketNum)
			{
				addServerDirectivesToServers(serverDirectives, servers);
				skipEmptyLinesAndCheckServerBlock(conf, false, servers);
			}
			continue ;
		}
		serverBlockIsNotEmpty = true;
		line = trimSpaces(line);

		if (line[0] == '#')
			continue ;

		std::istringstream iss(line);
		std::string directive;

		std::getline(iss, directive, ' ');
		directive = trimSpaces(directive);

		if (isLocationBlck)
		{
			if (directive == "location")
			{
				std::string locationDirective;
				std::getline(iss, locationDirective);
				if (locationDirective.empty() || isOnlyWhitespaces(locationDirective) || locationDirective == "{")
					throw std::runtime_error("The location directive is empty or contains only whitespaces.");
				locationDirective.resize(locationDirective.length() - 1);
				if (!(locationDirective.empty()) && !(isOnlyWhitespaces(locationDirective)))
					locationDirective = trimSpaces(locationDirective);
				if (containsWhitespace(locationDirective))
					throw std::runtime_error("The location directive contains whitespaces.");
				else if (locationDirective[0] != '/')
					throw std::runtime_error("The location directive should start with /.");
				serverLocations.setLocation(locationDirective);
				continue ;
			}
			locationBlockIsNotEmpty = true;
			checkLocation(serverLocations, iss, directive);
		}
		else if (directive == "server_name")
			checkServerName(serverDirectives, iss);
		else if (directive == "host")
			checkHost(serverDirectives, iss);
		else if (directive == "listen")
			checkListen(serverDirectives, iss);
		else if (directive == "root")
			checkRoot(serverDirectives, iss);
		else if (directive == "index")
			checkIndex(serverDirectives, iss);
		else if (directive == "client_max_body_size")
			checkMaxBodySize(serverDirectives, iss);
		else if (directive == "error_page")
			checkErrorPages(serverDirectives, iss);
		else if (directive == "autoindex")
			checkAutoIndex(serverDirectives, iss);
		else
			throw std::runtime_error("The config file contains an unknown or unsupported directive.");
	}
	if (startBracketNum != endBracketNum)
		throw std::runtime_error("The config file syntax is incorrect, there is no ending bracket.");
}
