#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


int main()
{

	// announcing the launch
	std::cout<<"This is the client\n";

	// creating the socket
	int client_socket = socket( AF_INET, SOCK_STREAM, 0);

	// connecting to the server
	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(9002);
	server_addr.sin_addr.s_addr = INADDR_ANY;

	// return with failure message if unsuccessful
	if ( connect( client_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1 )
	{
		std::cout<<"Failed creating the client connection with the server\n";
		return -1;
	}

	// read the message from server
	char buffer[200];
	recv(client_socket, &buffer, sizeof(buffer), 0); 

	// close socket and echo the message and return 
	close(client_socket);
	std::cout<<"Server response:"<<buffer<<"\n";
	return 0;
}

