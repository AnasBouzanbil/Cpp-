/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 03:56:41 by abouzanb          #+#    #+#             */
/*   Updated: 2023/10/07 03:56:42 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get.hpp"

ft_delete::ft_delete(Directives& k, std::string l, info &inf) : method_get(k, l,inf)
{
	this->keep = k;
	this->url = l;
	this->infa = inf;
	try 
	{
		this->location_check();
		this->check_stat();
		infa.buffer_to_send = extansion_handling["html"];
		infa.buffer_to_send = "HTTP/1.1 204 No Content\r\n\r\n";
		infa.status = 1;
	}
	catch (std::exception &e)
	{
		// std::cout << "DELETE : "<< e.what() << std::endl;
		infa.status = 1;
		return ;
	}
}

void ft_delete::remove_them(std::string path)
{
	struct stat st;
	DIR *dir;
	struct dirent *entry;
	if (!(dir = opendir(path.c_str())))
		return ;
	while ((entry = readdir(dir)) != NULL)
	{
		std::string name = entry->d_name;
		if (name == "." || name == "..")
			continue;
		std::string full_path = path + "/" + name;
		if (stat(full_path.c_str(), &st) == -1)
			continue;
		if (S_ISDIR(st.st_mode))
		{
			if (access(full_path.c_str(), F_OK) == -1)
				continue;
			remove_them(full_path);
			std::remove(full_path.c_str());
		}
		else
			remove_file(full_path);
	}
	closedir(dir);
	std::remove(path.c_str());
}

void ft_delete::remove_file(std::string path)
{
	if (std::remove(path.c_str()) ==0)
	{
		this->infa.buffer_to_send = "HTTP/1.1 204 No Content\r\n\r\n";
		this->infa.status = 1;
		size = 0;
		throw std::runtime_error("\e[42mFile is deleted\e[0m");
	}
	else if (errno == EACCES)
	{
		set_error_403();
	   throw std::runtime_error("\e[102mError: The file is not writable. response with 403\e[0m");
	}
}

void ft_delete::check_stat()
{
	struct stat st;
	if (stat(path.c_str() , &st) == 0)
	{
		if (access(path.c_str(), W_OK | X_OK) == -1)
		{
			set_error_403();
			throw std::runtime_error("\e[102mError: The file is not writable. response with 403\e[0m");
		}
		if (S_ISDIR(st.st_mode))
		{
			remove_them(path);
		}
		else
			remove_file(path);
	}
	else
	{
		set_error_404();
		throw std::runtime_error("\e[102mError: The file is not found. response with 404\e[0m");
	}
}

void ft_delete::location_check()
{
	int forbidden = 0;
	size_t i = 0;
	int max_lenght = 0;
	int size = 0;
	int is_checked = 0;
	while (i < keep.getLocationsVec().size())
	{
		size = keep.getLocationsVec()[i].getLocation().size();
		if (keep.getLocationsVec()[i].getLocation() == url.substr(0, size) && size >= max_lenght)
		{
			if (keep.getLocationsVec()[i].getAcceptedMethods()["DELETE"] == true)
			{
				max_lenght = size;
				this->route = keep.getLocationsVec()[i].getRoot();
				path = route + url.substr(size, url.size());
				// std::cout << "path: " << path << std::endl;
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
		throw std::runtime_error("\e[102mError: The method is not allowed. response with 403\e[0m");
	}
	if (is_checked == 0)
	{
		set_error_404();
		throw std::runtime_error("\e[102mError: The location is not found. response with 404\e[0m");
	}
}
