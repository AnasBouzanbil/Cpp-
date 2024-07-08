/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 03:56:52 by abouzanb          #+#    #+#             */
/*   Updated: 2023/10/08 03:38:39 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef get_hpp
#define get_hpp


#include <sys/wait.h>

#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <cstring>
#include <sys/stat.h> 
#include <sys/types.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sstream>
#include <signal.h>
#include <sys/types.h>
#include <dirent.h>
#include <libgen.h>
#include <map>
#include <netinet/tcp.h> 
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <cstring>
#include <sys/stat.h> 
#include <sys/types.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sstream>
#include <signal.h>
#include <sys/types.h>
#include <dirent.h>
#include <libgen.h>
#include <map>
#include <netinet/tcp.h>
#include   "../includes/Servers.hpp"
#include "../includes/conf_parser.hpp"

class info{
	public :
	info()
	{
		socket = 0;
		size = 0;
		file = NULL;
		status = 1;
		was_read = 0;
		is_hinged = 0;
	}
	~info()
	{
		delete file;
	}
	int was_read;
	int waitpid_ret;
	int pipe;
	int pid;
	int socket;
	int size;
	int status;
	int is_hinged;
	std::string path;
	std::string containte;
	std::ifstream *file;
	std::string buffer_to_send;
};

class method_get
{
	protected:
		std::map<std::string, std::string> map;
		std::map<std::string, std::string> extansion_handling;
		std::string path;
		std::string route;
		std::string extansion;
		bool auto_index;
	std::vector<std::string> index;
	public :
		int size;
		std::ifstream *file;
		std::string url;
		info &infa;
		Directives& keep;
		std::map<std::string , std::string> erros_page;
		std::string location;
	method_get(Directives& k, std::string l, info &inf);
	void get_check_path();
	void folder_handling();
	void file_handling();
	void handle_auto_index();
	void set_error_404();
	void set_error_500();
	void set_error_403();
	void check_location();
	void send_indexing(DIR *dir);
	void execute_cgi(std::string &path,std::string &arguments, std::string &run_it);
	void set_extasion();
	void get_element_from_location(int& checked_cgi, int& forbidden , int &size, int &max_lenght, int &auto_index);
	void waiting_for_child( int *fd);
};

class ft_delete : public method_get
{

    public :
    ft_delete(Directives& k, std::string l, info &inf);
    void location_check();
    void remove_them(std::string path);
    void check_stat();
    void remove_file(std::string path);
    void remove_folder(std::string path);
};
void ft_get(Directives &data, std::string url,  info &socket);


#endif