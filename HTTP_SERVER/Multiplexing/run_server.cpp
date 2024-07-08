#include "../Request/POST/ft_Post.hpp"

int check_spaces(std::string &str)
{
	int i = 0;
	int spaces = 0;
	while (str[i] && str[i] != '\r')
	{
		if (str[i] == ' ')
			spaces++;
		i++;
	
	}
	return (spaces);
}

int  check_which_method(std::string& headers, t_client_info *client, fd_set &writes, std::vector<int> &clientSockets, std::vector<Directives> &serversVec)
{
	int ret;
	if (client->times == 0)
	{
		int start = headers.find(" ") + 1;
		client->method = headers.substr(0, headers.find(" "));
		client->url = headers.substr(start, headers.find(" ", start) - start);
		std::string version = headers.substr(headers.find(" ", start) + 1, headers.find("\r\n") - headers.find(" ", start) - 1);
		if (check_spaces(headers) != 2)
		{
			// std::cout << "\e\e[91mError : Bad Request\e[0m" << std::endl;
			client->Info->buffer_to_send = "HTTP/1.1 400 Bad Request\r\n\r\n";
			client->Info->status = 1;
			FD_SET(client->socket, &writes);
			return 1;
		}
		if (client->method != "GET" && client->method != "POST" && client->method != "DELETE")
		{
			// std::cout << "\e\e[91mError : Method Not Allowed or Not Implemented\e[0m" << std::endl;
			client->Info->buffer_to_send = "HTTP/1.1 501 Not Implemented\r\n\r\n";
			client->Info->status = 1;
			FD_SET(client->socket, &writes);

			return 1;
		}
		if (version != "HTTP/1.1")
		{
			// std::cout << "\e\e[91mError : HTTP Version Not Supported\e[0m" << std::endl;
			client->Info->buffer_to_send = "HTTP/1.1 505 HTTP Version Not Supported\r\n\r\n";
			client->Info->status = 1;
			FD_SET(client->socket, &writes);
			return 1;
		}
	}
	if (client->method == "GET")
	{
		client->times = 1; // for charaf hena rah khdemt b times dialk bach mayb9ach idkhol lfo9 meli tkkon get  method m3aha body
		client->method = "GET";
		// std::cout << "\e[96mMethod : GET\e[0m" << std::endl;
		client->Info->socket = client->socket;
		ft_get(client->data, client->url, *(client->Info));
		if (!FD_ISSET(client->socket, &writes))
			FD_SET(client->socket, &writes);
		return 0;
	}
	else if (client->method == "POST")
	{
		client->method = "POST";
		ret = handle_Post(clientSockets, serversVec, client);
		if (ret == 3)
		{
			// std::cout << "it gave 3" << std::endl;
			if (!FD_ISSET(client->socket, &writes))
				FD_SET(client->socket, &writes);
		}
		else if ((ret == 1 && client->all_received >= client->bl) || (ret == 0 && client->req_body.find("\r\n0\r\n\r\n") != std::string::npos))
			if (!FD_ISSET(client->socket, &writes))
				FD_SET(client->socket, &writes);
		return 0;
	}
	else if (client->method == "DELETE")
	{
		client->times = 1;
		// std::cout << "\e[96mMethod : DELETE\e[0m" << std::endl;
		client->method = "DELETE";
		client->Info->socket = client->socket;
		ft_delete(client->data, client->url, *(client->Info));
		FD_SET(client->socket, &writes);
		return  0;
	}
	else 
	{
		// std::cout << "\e\e[91mError : Bad Request\e[0m" << std::endl;
		client->Info->buffer_to_send = "HTTP/1.1 400 Bad Request\r\n\r\n";
		client->Info->status = 1;
		return 1;
	}
	return 1;

}

void	runServer(Servers &servers)
{
	t_client_info *clients = NULL;
	std::vector<Directives> serversVec = servers.getServersVec();
	std::vector<int> serverSockets(serversVec.size());
	std::vector<int> clientSockets;

	for (size_t i = 0; i < serversVec.size(); i++)
	{
		std::string	host = serversVec[i].getHost();
		int			port = serversVec[i].getListen();
		serverSockets[i] = createListeningSocket(host, port);
	}

	fd_set	reads;
	fd_set	writes;
	fd_set	tempReads;
	fd_set	tempWrites;
	int		maxSocket;

	FD_ZERO(&reads);
	FD_ZERO(&writes);
	maxSocket = 0;

	for (size_t i = 0; i < serverSockets.size(); i++)
	{
		FD_SET(serverSockets[i], &reads);
		if (serverSockets[i] > maxSocket)
			maxSocket = serverSockets[i];
	}

	while (true)
	{
		wait_on_clients(maxSocket, &clients, reads, writes, tempReads, tempWrites);
		for (size_t i = 0; i < serverSockets.size(); i++)
		{
			if (FD_ISSET(serverSockets[i], &tempReads))
			{
				t_client_info *newClient = new t_client_info;
				newClient->address_length = sizeof(newClient->address);
				newClient->socket = accept(serverSockets[i], (struct sockaddr*)&(newClient->address), &(newClient->address_length));
				newClient->data = serversVec[i];
				newClient->serverIndex = i;
				if (newClient->socket == -1)
					throw std::runtime_error("Error accepting connection");
				ft_lstadd_back(&clients, newClient);
				clientSockets.push_back(newClient->socket);
				// std::cout << "New connection from " << get_client_address(client) << "." << std::endl;
			}
		}
		t_client_info *client = clients;
		while(client)
		{
			t_client_info *next = client->next;
			if (FD_ISSET(client->socket, &tempReads))
			{
				client->received = recv(client->socket, client->request, 60000, 0);
				client->all_received+=client->received;
				if (client->received == -1)
				{
					std::cout << "bgb" << std::endl;
					// std::cerr << "Error reading from client " << get_client_address(client) << "." << std::endl;
					drop_client(client, &clients, reads, writes);
				}
				else if (client->received == 0)
				{
					std::cout << "bgb" << std::endl;
					// std::cerr << "Client socket " << client->socket << " closed." << std::endl;
					drop_client(client, &clients, reads, writes);
				}
				else
				{
                    // std::cout << "Received " << client->received << " bytes from client " << get_client_address(client) << "." << std::endl;
					std::string header = client->request;
					check_which_method(header, client, writes, clientSockets, serversVec);
				}
			}
			client = next;
		}
		t_client_info *client_write = clients;
		while(client_write)
		{
			t_client_info *next = client_write->next;
			if (FD_ISSET(client_write->socket, &tempWrites))
			{
				if (client_write->method == "POST")
				{
					response(client_write, clientSockets, serversVec);
					drop_client(client_write, &clients, reads, writes);
				}
				else
					get_response(*(client_write->Info), client_write, &clients, reads, writes);
			}
			client_write = next;
		}
	}
	for (size_t i = 0; i < serverSockets.size(); i++)
		close(serverSockets[i]);
}
