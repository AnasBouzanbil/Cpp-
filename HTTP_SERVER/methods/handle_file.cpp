/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_file.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 03:56:59 by abouzanb          #+#    #+#             */
/*   Updated: 2023/10/07 03:57:56 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get.hpp"

void method_get::file_handling()
{
	infa.file = new std::ifstream(path.c_str(), std::ios::binary);
	if (!infa.file->is_open())
	{
		this->set_error_404();
		infa.status = 1;
		return;
	}
	std::stringstream ss ;
	std::string ext;
	size_t i = path.find_last_of(".");
	if (i == std::string::npos)
		ext = ".html";
	ext =  path.substr(i, path.size());
	std::string extansion =  extansion_handling[ext];
	if (extansion == "")
		extansion = extansion_handling[".html"];
	ss << this->size;
	extansion += ss.str();
	extansion += "\r\n";
	extansion += "\r\n";
	this->infa.buffer_to_send = extansion;
	this->infa.status = 1;
}
