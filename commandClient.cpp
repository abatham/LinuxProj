#include <iostream>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <string.h>
#include <unistd.h>


int main(int argc, char ** argv)
{

	if ( argc < 2)
	{
		std::cout<<"Provide a port number to connect to\n";
		return -1;
	}
	std::cout<<"Client starting up...\n";

	int clientSock = socket( AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons( std::stoi( argv[1] ));
	servAddr.sin_addr.s_addr = INADDR_ANY;

	if (connect( clientSock, (struct sockaddr *) &servAddr, sizeof(servAddr)) == -1 )
	{
		std::cout<<"Couldn't connect to the server\n";
		return -1;
	}

	char buffer[200];
//	buffer[0] = 'X';
/*	std::cout<<"Enter a command for server :\n";
	std::cin>>buffer[0];
*/
	buffer[0] = *argv[2];
	buffer[1] = *argv[3];
	send(clientSock, buffer, sizeof(buffer), 0);

	close(clientSock);

	return 0;
}
