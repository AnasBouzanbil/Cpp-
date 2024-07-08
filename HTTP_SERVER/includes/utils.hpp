#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include <dirent.h>
#include <unistd.h>
#include "Directives.hpp"
#include "Locations.hpp"
#include "Servers.hpp"

bool		isOnlyWhitespaces(const std::string& str);
std::string	trimSpaces(const std::string& str);
void		removeWhitespaces(std::string& str);
bool		charIsInString(const std::string& str, const char ch);
bool		isIPAddress(const std::string &str);
bool		isValidDomainSegment(const std::string &segment);
bool		isDomainName(const std::string &str);
bool		isAlphanumeric(const std::string &str);
bool		containsWhitespace(const std::string& str);
void		splitString(const std::string& str, std::vector<std::string>& result);
bool		isNum(const std::string& str);
std::string removeExtraWhitespace(const std::string &str);
bool		isDirectory(const char* path);
bool		isLocationBlock(const std::string& line);

#endif