/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 03:56:24 by abouzanb          #+#    #+#             */
/*   Updated: 2023/10/08 05:45:17 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get.hpp"
#include "../Multiplexing/multiplexing.hpp"
#define P 8081



// hndling cgi
 
void method_get::waiting_for_child( int *fd)
{
	char buf[1024];
	std::string str;
	std::ofstream temp(".file.txt");
	while (read(fd[0], buf, 1024) > 0)
	{
		str = buf;
		temp << str;
	}
	close(fd[0]);
	temp.close();
	infa.file = new std::ifstream(".file.txt");
	if (infa.file->is_open() == false)
	{
		set_error_500();
		throw std::exception();
	}
	struct stat st;
	stat(".file.txt", &st);
	infa.size = st.st_size;
	infa.status = 1;
	std::stringstream ss;
	ss << infa.size;
	infa.file = new std::ifstream(".file.txt");
	infa.buffer_to_send = "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: " + ss.str() + "\r\n\r\n";
	infa.is_hinged = 0;	
	std::runtime_error("\e[91mThe cgi is executed \e[0m");
}
 

void method_get::execute_cgi(std::string &path, std::string &arguments, std::string& run_it)
{
	int fd[2];
	pid_t pid;
	char *argv[4];
	std::string str;
	char *envp[5];
	struct stat st;
	if (stat(path.c_str(), &st) == -1)
	{
		set_error_404();
		throw std::runtime_error("\e[91mError: The file is not found. response with 404\e[0m");
	}
	if (access(path.c_str(), R_OK) == -1)
	{
		set_error_403();
		throw std::runtime_error("\e[91mError: The file is not readable. response with 403\e[0m");
	}
	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		argv[0] = strdup(run_it.c_str());
		argv[1] = strdup(path.c_str());
		argv[2] = NULL;
		envp[0] = strdup("REQUEST_METHOD=GET");
		str = "SCRIPT_NAME=" + path;
		envp[2] = strdup(str.c_str());
		if (arguments != "")
		{
			envp[3] = strdup(arguments.c_str());
			envp[4] = NULL;	
		}
		else
			envp[3] = NULL;
		execve(run_it.c_str(), argv, envp);
		exit(0);
	}
	else
	{
		close(fd[1]);
		infa.waitpid_ret = waitpid(pid, NULL, WNOHANG);
		if (infa.waitpid_ret == -1)
		{
			set_error_500();
			throw std::runtime_error("\e[91mError: The cgi is not executed. response with 500\e[0m");
		}
		else if (infa.waitpid_ret == pid)
		{
			waiting_for_child( fd);
		}
		else if (infa.waitpid_ret == 0)
		{
			infa.pipe = fd[0];
			infa.pid = pid;
			infa.is_hinged = 1;
			std::runtime_error("\e[91m the cgi is hunged\e[0m");
			//contuine the execution and handle the cgi in another function when the return of waitpid is noy zero and it is the pid of the child process
		}
	}
}

int check_is_cgi(std::string& path, std::string& real_path, std::string& extansion, std::string arguments)
{	
	
	if (path.find(".php") != std::string::npos)
	{
		if (path.find(".php") + 4 == path.find("?"))
		{
			extansion = ".php";
			real_path = path.substr(0, path.find("?"));
			arguments = "QUERY_STRING=" + path.substr(path.find("?") + 1, path.size());
			return 1;
		}
		else if (path.size() >= 4 && path.substr(path.size() - 4) == ".php")
		{
			extansion = ".php";
			real_path = path;
			arguments = "";
			return 1;
		}
	}
	else if (path.find(".py") != std::string::npos)
	{
		if (path.find(".py") + 3 == path.find("?"))
		{
			extansion = ".py";
			real_path = path.substr(0, path.find("?"));
			arguments = "QUERY_STRING=" + path.substr(path.find("?") + 1, path.size());
			return 1;
		}
		else if (path.size() >= 3 && path.substr(path.size() - 3) == ".py")
		{
			extansion = ".py";
			real_path = path.substr(0, path.find_last_of(".py") + 3);
			arguments = "";
			return 1;
		}
	}
	return 0;
}


// handling the request

void method_get::check_location()
{
	int forbidden = 0;
	std::string let;
	size_t i = 0;
	int max_lenght = 0;
	std::string ext;
	std::string arguments;
	int checked_cgi = 0;
	std::string cgi_script;
	int is_checked = 0;
	while (i < keep.getLocationsVec().size())
	{
		size = keep.getLocationsVec()[i].getLocation().size();
		if (keep.getLocationsVec()[i].getLocation() == url.substr(0, size) && size >= max_lenght)
		{
			if (keep.getLocationsVec()[i].getAcceptedMethods()["GET"] == true)
			{
				max_lenght = size;
				this->auto_index = keep.getLocationsVec()[i].getAutoIndex();
				this->index = keep.getLocationsVec()[i].getIndex();
				this->route = keep.getLocationsVec()[i].getRoot();
				if (route[route.size() - 1] != '/')
					route += "/";
				path = route + url.substr(size, url.size());
				if (keep.getLocationsVec()[i].getCgi().size() != 0)
				{
					// std::cout << "cgi" << std::endl;
					std::string ext;
					if (check_is_cgi(path, let, ext, arguments)== 1)
					{
						
						if (keep.getLocationsVec()[i].getCgi()[ext] == "/usr/bin/php" || keep.getLocationsVec()[i].getCgi()[ext] == "/bin/python3")
						{
							
							checked_cgi = 1;
							cgi_script = keep.getLocationsVec()[i].getCgi()[ext];
						}
						else 
							checked_cgi = 0;
					}
				}
				else 
					checked_cgi = 0;
				if (keep.getLocationsVec()[i].getReturn() != "")
				{
					// std::cout << keep.getLocationsVec()[i].getReturn() << std::endl;
					infa.buffer_to_send = "HTTP/1.1 302 " + keep.getLocationsVec()[i].getReturn() + "\nContent-Type: text/html\nContent-Length: 0\r\n\r\n";
					this->infa.status = 1;
					throw std::exception();					
				}
				is_checked = 1;
				forbidden = 0;
			}
			else
				forbidden = 1;
		}
		i++;
	}

	if (forbidden == 1)
	{
		set_error_403();
		throw std::runtime_error("\e[91mError: The method is not allowed. response with 403\e[0m");
	}
	if (checked_cgi == 1)
	{
		execute_cgi(let,  arguments, cgi_script);
	}
	if (is_checked == 0)
	{
		set_error_404();
		throw std::runtime_error("\e[91mError: The location is not found. response with 404\e[0m");
	}
}

void method_get::get_check_path()
{
	struct stat st;
	try {
			check_location();
			if (stat(path.c_str() , &st) == 0)
			{
					if (access(path.c_str(), R_OK) == -1)
					{
						set_error_403();
						throw std::runtime_error("\e[91mError: The file is not readable. response with 403\e[0m");
					}
					this->size = st.st_size;
					infa.size = st.st_size;
					if (S_ISDIR(st.st_mode))
						folder_handling();
					else
					{
						file_handling();
						throw 	std::runtime_error("\e[42mFile is requested , resopnse with file\e[0m");
					}
			}
			else
			{
				set_error_404();
				throw std::runtime_error("\e[91mError: The file is not found. response with 404\e[0m");
			}
	}
	catch (const std::exception& e)
	{
		std::cout << "\e[36mGET METHOD  : "  << e.what() << std::endl;
	}
}

void method_get::set_extasion()
{
	std::string moth = "HTTP/1.1 200 OK\n";
	extansion_handling[".html"] = moth + "Content-Type: text/html\nContent-Length: ";
	extansion_handling[".css"] = moth + "Content-Type: text/css\nContent-Length: ";
	extansion_handling[".js"] = moth + "Content-Type: text/javascript\nContent-Length: ";
	extansion_handling[".jpg"] = moth + "Content-Type: image/jpeg\nContent-Length: ";
	extansion_handling[".jpeg"] = moth + "Content-Type: image/jpeg\nContent-Length: ";
	extansion_handling[".png"] = moth + "Content-Type: image/png\nContent-Length: ";
	extansion_handling[".gif"] = moth + "Content-Type: image/gif\nContent-Length: ";
	extansion_handling[".mp4"] = moth + "Content-Type: video/mp4\nContent-Length: ";
	extansion_handling[".mp3"] = moth + "Content-Type: audio/mpeg\nContent-Length: ";
	extansion_handling[".pdf"] = moth + "Content-Type: application/pdf\nContent-Length: ";
	extansion_handling[".txt"] = moth + "Content-Type: text/plain\nContent-Length: ";
	extansion_handling["404"] = "HTTP/1.1 404 Not Found\nContent-Type: text/html\nContent-Length: ";
	extansion_handling["403"] = "HTTP/1.1 403 Forbidden\nContent-Type: text/html\nContent-Length: ";
	extansion_handling["500"] = "HTTP/1.1 500 Internal Server Error\nContent-Type: text/html\nContent-Length: ";
}

method_get::method_get(Directives& k , std::string url, info &inf) : infa(inf) , keep(k)
{
	this->keep = k;
	std::string route = k.getRoot();
	this->path = route + url;
	auto_index = k.getAutoIndex();
	this->url = url;
	infa.path = path;
	this->erros_page = k.getErrorPages();
	this->set_extasion();
}


void ft_get(Directives &data, std::string url,  info &socket)
{
	if (socket.was_read == 1)
		return ;
	method_get get(data, url,  socket);
	get.get_check_path();
	socket.was_read = 1;
}






// response part 
void send_file_in_response(info &clientes, t_client_info *client_write , t_client_info **clients, fd_set &reads, fd_set &writes)
{
	char bu[1025];
	clientes.file->read(bu, 1024);
	int reading = clientes.file->gcount();
	// std::cout << "\e[96mGET : \e[42mSending data to the socket " << clientes.socket << "\e[0m" << std::endl;
	int sending   = send(clientes.socket, bu, reading, 0) ;
	if	(sending < 0) // here it will check if the send function returns -1 , if it does it will close the socket and drop the client
	{
		// std::cout << "\e[91mGet : \e[42mError : an error occured with the socket " << clientes.socket <<  ", while sending the file\e[0m" << std::endl;
		if (clientes.file)
			clientes.file->close();
		drop_client(client_write, clients, reads, writes);
		return ;
	}
	if (sending == 0)
	{
		// std::cout << "\e[91mGet : \e[42mThe file is empty the send function returns 0  \e[0m" << std::endl;
		if (clientes.file)
			clientes.file->close();
		drop_client(client_write, clients, reads, writes);
		return ;
	}
}

void send_header_in_response(info &clientes, t_client_info *client_write , t_client_info **clients, fd_set &reads, fd_set &writes)
{
	// std::cout << "\e[96mGET : \e[42mSending header to the socket " << clientes.socket << "\e[0m" << std::endl;
	if (send(clientes.socket, clientes.buffer_to_send.c_str(), clientes.buffer_to_send.size(), 0) < 0)
	{
		if (clientes.file)
			clientes.file->close();
		drop_client(client_write, clients, reads, writes);
		return ;
	}
	clientes.status = 0;	
}

void handle_hunged_cgi_client(info &clientes)
{
	struct stat st;
	std::stringstream ss;
	char bu[1025];
	
	std::ofstream out(".file.txt");
	while (read(clientes.pipe, bu, 1024) > 0)
		out << bu;
	out.close();
	stat(".file.txt", &st);
	clientes.size = st.st_size;
	ss << clientes.size;
	clientes.file = new std::ifstream(".file.txt");
	clientes.buffer_to_send = "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: " + ss.str() + "\r\n\r\n";
	// std::cout << "\e[96mGET : \e[42mThe cgi is executed after time\e[0m" << std::endl;
	clientes.is_hinged = 0;
	clientes.status = 1;
}

void	get_response(info &clientes, t_client_info *client_write , t_client_info **clients, fd_set &reads, fd_set &writes)
{
	if (clientes.is_hinged == 1)
	{
		clientes.waitpid_ret = waitpid(clientes.pid, NULL, WNOHANG);
		if (clientes.waitpid_ret == clientes.pid)
			handle_hunged_cgi_client(clientes);
		return ;
	}
	if (clientes.status == 1) // here it will send the header onece and the clientes.status will be 0 , to not send it again
		send_header_in_response(clientes, client_write, clients, reads, writes);
	else if (clientes.file && clientes.file->eof() == false) // here it will send the file if the response contains a file, and the file is not finished yet 
		send_file_in_response(clientes, client_write, clients, reads, writes);
	else // here in case the file is finished or there is no file to send , it will close the socket and drop the client
	{
		// std::cout << "\e[96mGET : \e[41mClosing the socket " << clientes.socket << "\e[0m" << std::endl;
		if (clientes.file)
			clientes.file->close();
		drop_client(client_write, clients, reads, writes);
		return ;
	}
}
