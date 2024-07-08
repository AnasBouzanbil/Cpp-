#ifndef PARSE_CONF_HPP
#define PARSE_CONF_HPP

#include "check_directives.hpp"

void	checkLocationRoot(Locations &location, std::istringstream &iss);
void	checkLocationIndex(Locations &location, std::istringstream &iss);
void	checkLocationAutoIndex(Locations &location, std::istringstream &iss);
void	checkLocationAcceptedMethods(Locations &location, std::istringstream &iss);
void	checkLocationReturn(Locations &location, std::istringstream &iss);
void	checkLocationCgi(Locations &location, std::istringstream &iss);
void	checkLocationUploadStore(Locations &location, std::istringstream &iss);
void	checkLocation(Locations &location, std::istringstream &iss, std::string directive);

#endif