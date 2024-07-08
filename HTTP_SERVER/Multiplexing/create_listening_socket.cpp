#include "multiplexing.hpp"

int	createListeningSocket(std::string &host, int &port)
{
	const char*			ptrPort;
	int					socket_listen;
	int					addr_res;
	int					bind_res;
	int					listen_res;
	std::ostringstream	oss;
	std::string			result;
	struct addrinfo		hints;
	struct addrinfo		*bind_address;
	int option_value = 1;
	int ret;

    oss << port;
    result = oss.str();
    ptrPort = result.c_str();

	std::cout << "Configuring local address..." << std::endl;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	addr_res = getaddrinfo(host.c_str(), ptrPort, &hints, &bind_address);
	if (addr_res != 0)
		throw std::runtime_error("Failed to resolve hostname to IP address.");

	// std::cout << "Creating listening socket for server block listening in port : " << port << "..." << std::endl;
	socket_listen = socket(bind_address->ai_family, bind_address->ai_socktype, bind_address->ai_protocol);
	if (socket_listen == -1)
		throw std::runtime_error("Failed to create socket for server block.");
	ret = setsockopt(socket_listen, SOL_SOCKET,SO_REUSEADDR, &option_value,sizeof(option_value));
	if (ret == -1)
		throw std::runtime_error("Failed to set socket option for server block.");

	// std::cout << "Binding the socket to the address and the port..." << std::endl;
	bind_res = bind(socket_listen, bind_address->ai_addr, bind_address->ai_addrlen);
	if (bind_res == -1)
		throw std::runtime_error("Bind failed: Unable to bind the socket to the specified host and port.");
	freeaddrinfo(bind_address);

	// std::cout << "Listening on " << host << ":" << port << "..." << std::endl;
	listen_res = listen(socket_listen, 10);
	if (listen_res == -1)
		throw std::runtime_error("Listen failed: Unable to start listening for incoming connections.");

	// std::cout << "Listening socket created on port : " << port << "." << std::endl;

	return (socket_listen);
}
