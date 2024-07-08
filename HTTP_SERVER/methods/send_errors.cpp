/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_errors.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 03:57:31 by abouzanb          #+#    #+#             */
/*   Updated: 2023/10/07 03:57:32 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "get.hpp"

void method_get::set_error_500()
{
	// std::cout << "error 500" << std::endl;
	std::ofstream file("./error500.html");
	file << "<html><body><h1>500 Internal Server Error</h1></body></html>";
	file.close();
	this ->path  = "./error500.html";
	struct stat st;
	stat(path.c_str() , &st);
	std::stringstream ss ;
	ss << st.st_size;
	infa.buffer_to_send = extansion_handling["500"] + ss.str() + "\r\n\r\n";
	infa.file = new std::ifstream(path.c_str(),  std::ios::binary);
}

void	method_get::set_error_403()
{
	std::stringstream ss ;
	std::string ext;
	struct stat st;
	this ->path  = erros_page["403"];
	this->file = new std::ifstream(path.c_str(),  std::ios::binary);
	if (!file->is_open())
	{
		this->set_error_500();
		infa.status = 1;
		return;
	}
	stat(path.c_str() , &st);
	this->size = st.st_size;
	infa.size = st.st_size;
	ext = extansion_handling["403"];
	ss << this->size;
	ext += ss.str();
	ext += "\r\n\r\n";
	this->infa.buffer_to_send = ext;
	this->infa.status = 1;
	infa.file = file;
}

void	method_get::set_error_404()
{
	struct stat st;
	std::stringstream	ss;
	std::string			ext;
	this ->path  = erros_page["404"];
	infa.file = new std::ifstream(path.c_str(),  std::ios::binary);
	if (!infa.file->is_open())
	{
		this->set_error_500();
		return;
	}
	stat(path.c_str() , &st);
	this->size = 		st.st_size;
	infa.size = 		st.st_size;
	ext = extansion_handling["404"];
	ss << this->size;
	ext += ss.str();
	ext += "\r\n\r\n";
	this->infa.buffer_to_send = ext;
	this->infa.status = 1;
}
