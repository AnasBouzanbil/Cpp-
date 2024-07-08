#include "../includes/utils.hpp"

std::string	trimSpaces(const std::string& str)
{
    size_t start = str.find_first_not_of(" \t\r\n");
    size_t end = str.find_last_not_of(" \t\r\n");

    return (str.substr(start, end - start + 1));
}

bool	isOnlyWhitespaces(const std::string& str)
{
    for (std::string::const_iterator it = str.begin(); it != str.end(); it++)
	{
        if (!std::isspace(*it))
            return (0);
    }
    return (1);
}

void removeWhitespaces(std::string& str)
{
    std::string::iterator	it = str.begin();
    while (it != str.end())
    {
        if (std::isspace(*it))
            it = str.erase(it);
		else
			it++;
    }
}

bool	charIsInString(const std::string& str, const char ch)
{
    return (str.find(ch) != std::string::npos);
}

bool	isIPAddress(const std::string &str)
{
	std::istringstream iss(str);
	std::string segment;

	int	numSegments;
	int num;

	numSegments = 0;
	while (std::getline(iss, segment, '.'))
	{
		if (!(std::istringstream(segment) >> num))
			return (false);
		if (num < 0 || num > 255)
			return (false);
        numSegments++;
    }

    return (numSegments == 4);
}

bool	isValidDomainSegment(const std::string &segment)
{
    if (segment.empty() || segment.length() > 63)
        return (false);

    for (unsigned int i = 0; i < segment.length(); i++)
	{
        if (!std::isalnum(segment[i]) && segment[i] != '-')
            return (false);
    }

	if (isNum(segment))
		return (false);

    if (segment[0] == '-' || segment[segment.length() - 1] == '-')
        return (false);

    return (true);
}

bool	isDomainName(const std::string &str)
{
    std::vector<std::string>	segments;
    std::string					segment;

    for (unsigned int i = 0; i < str.length() ; i++)
	{
		if (str[i] == '.')
		{
            if (!isValidDomainSegment(segment))
                return (false);
            segments.push_back(segment);
            segment.clear();
        }
		else
            segment.push_back(str[i]);
    }

    if (!isValidDomainSegment(segment))
        return (false);

    segments.push_back(segment);

    return (!segments.empty());
}


bool	isAlphanumeric(const std::string &str)
{
	if (isNum(str))
		return (false);
    for (unsigned int i = 0; i < str.length() ; i++)
	{
        if (!std::isalnum(str[i]) && str[i] != '_')
            return (false);
    }
    return (true);
}

bool	containsWhitespace(const std::string& str)
{
    for (std::string::const_iterator it = str.begin(); it != str.end(); it++)
	{
        if (std::isspace(static_cast<unsigned char>(*it)))
            return (true);
    }
    return (false);
}

void	splitString(const std::string& str, std::vector<std::string>& result)
{
    std::string substring;
    result.clear();
    
	substring = "";
    for (size_t i = 0; i < str.size(); i++)
	{
        if (str[i] == ' ')
		{
			result.push_back(substring);
			substring = "";
        }
		else
			substring += str[i];
    }
	if (!substring.empty())
        result.push_back(substring);
}

bool	isNum(const std::string& str)
{
    for (size_t i = 0; i < str.length(); i++)
	{
        if (!std::isdigit(str[i]))
            return (false);
    }
    return (true);
}

bool	isDirectory(const char* path)
{
    DIR* dir = opendir(path);
    if (dir)
	{
        closedir(dir);
        return (true);
    }
	else
        return (false);
}

std::string removeExtraWhitespace(const std::string &str)
{
    std::string result;
    bool inWhitespace = false;

    for (unsigned int i = 0; i < str.length(); i++)
	{
        if (std::isspace(str[i]))
		{
            if (!inWhitespace)
			{
                result += ' ';
                inWhitespace = true;
            }
        }
		else
		{
            result += str[i];
            inWhitespace = false;
        }
    }

    return (result);
}

bool	isLocationBlock(const std::string& line)
{
	std::string str = "location";
    if (line.length() >= str.length() && line[line.length() - 1] == '{')
        return (line.compare(0, str.length(), str) == 0);
    else
        return (false);
}
