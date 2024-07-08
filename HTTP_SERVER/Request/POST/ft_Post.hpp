#ifndef FT_POST_HPP
#define FT_POST_HPP

#include <string>
#include <sys/socket.h>
#include <sys/types.h> 
#include <fcntl.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <poll.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../../Multiplexing/multiplexing.hpp"

int ft_my_Post(t_client_info *client);
std::string* get_body(t_client_info *client, Directives &working);
void response(t_client_info* client, std::vector<int> clientSockets, std::vector<Directives> &servers);
std::string grab_path(std::string& req);
std::string* handle_cgi(t_client_info *client, Directives& working, int flag);
size_t hextodec(const char *s);
ssize_t get_length(std::string& req);
void handle_content_length(t_client_info* client ,std::string& req_body, int binary_data_start);
void handle_chunked_encoding(t_client_info* client, const std::string& chunked_data);
std::string* grab_method(std::string& req);
int handle_Post(std::vector<int> &clientSockets, std::vector<Directives> &servers, t_client_info *client);

#endif