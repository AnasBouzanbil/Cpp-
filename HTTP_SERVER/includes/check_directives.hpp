#ifndef CHECK_DIRECTIVES_HPP
#define CHECK_DIRECTIVES_HPP

#include "utils.hpp"

void			checkServerName(Directives &directives, std::istringstream &iss);
void			checkHost(Directives &directives, std::istringstream &iss);
void			checkListen(Directives &directives, std::istringstream &iss);
void			checkRoot(Directives &directives, std::istringstream &iss);
void			checkIndex(Directives &directives, std::istringstream &iss);
void			checkMaxBodySize(Directives &directives, std::istringstream &iss);
void			checkErrorPages(Directives &directives, std::istringstream &iss);
void			checkAutoIndex(Directives &directives, std::istringstream &iss);

#endif