/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_folder.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 03:57:04 by abouzanb          #+#    #+#             */
/*   Updated: 2023/10/07 03:57:05 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get.hpp"


void method_get::send_indexing(DIR *dir)
{
	struct dirent *dp;
    std::ofstream  fill("./indexing.html");
	struct stat st;
    if (!fill.is_open())
    {
        // std::cout << "error in opening file" << std::endl;
        return ; 
    }
	fill << "<html>\n<head>\n<title>Index of " << url << "</title>\n <style> body {background-color: Cyan; font-size: 14px}</style>\n</head>\n<body>\n<h1>Index of " << url << "</h1>\n<hr>\n<pre>\n";
 	while ((dp = readdir(dir)) != NULL)
        fill << "<a href=\"" << url + dp->d_name << "\">" << dp->d_name << "</a>\n";
	fill << "</pre><hr>\n</body>\n</html>\n";
	closedir(dir);
	fill.close();
	this->path = "./indexing.html";
	stat(path.c_str() , &st);
	this->size = st.st_size;
	file_handling();
	std::runtime_error("\e[91mFolder is requested , resopnse with indexing its content\e[0m");
}

void	method_get::handle_auto_index()
{

	DIR	*dir;
	if	((dir = opendir(path.c_str())) == NULL)
		set_error_404();
	else
		send_indexing(dir);
}

void	method_get::folder_handling()
{
	struct stat	st;
	size_t	i = 0;	
	while (i < this->index.size())
	{
		// std::cout << "index : " << index[i] << std::endl;
		std::string temp = path;
		temp += index[i];
		if (stat(temp.c_str() , &st) == 0)
		{
			this->size = st.st_size;
			infa.size = st.st_size;
			this->path = temp;
			file_handling();
			throw std::runtime_error("\e[91mFolder is requested , resopnse with index\e[0m");
		}
		i++;
	}
	if (this->auto_index == true)
		handle_auto_index();
	else
		set_error_403();
}
