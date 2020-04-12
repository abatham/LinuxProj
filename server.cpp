#include <iostream>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#include <chrono>
#include <ctime>
#include <sstream>
#include <string.h>
#include <string>

int main()
{
	// announcing the launch
	std::cout<<"This is the Server\n";

	// creating the socket
	int server_socket = socket( AF_INET, SOCK_STREAM, 0);


	struct sockaddr_in server_addr;
	server_addr.sin_port = htons(9002);
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_family = AF_INET;

	bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));

	listen(server_socket, 3);

	int client_conn = accept(server_socket, NULL, NULL);

	auto timeNow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::stringstream ss;
	ss<<"Server was pinged at ";
	ss<<ctime(&timeNow);
	std::string msg = ss.str();
	send(client_conn, msg.c_str(), msg.size(), 0);

	//close(client_conn);
	//close(server_socket);

	return 0;
}

