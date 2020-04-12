#include <iostream>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include <string.h>


int main(int argc, char ** argv)
{
	std::cout<<"Launching Server...\n";

        if ( argc < 2 )
        {
                std::cout<<"Provide the port number\n";
                return -1;
        }

	int servSocket = socket( AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(std::stoi( argv[1] ));
	servAddr.sin_addr.s_addr = INADDR_ANY;

	bind( servSocket, (struct sockaddr *) &servAddr, sizeof(servAddr));

	listen( servSocket, 10);

	int clientSock = accept( servSocket, 0 , 0);

	char buffer[50];
	recv( clientSock, buffer, sizeof(buffer), 0);

	switch( buffer[0] )
	{
		case 'A':
			std::cout<<"Client is asking for time..\n";
			break;
		case 'B':
			std::cout<<"Client is just saying hello :) \n";
			break;
		case 'C':
			std::cout<<"Client wants a file :O\n";
			break;
		case 'X':
			std::cout<<"Server asked to shut down..\nShutting down\n";
			return 0;
		default :
			std::cout<<"Looks like its a new client and is not aware of all the options..\n";
			break;
	}

	close(clientSock);
	close(servSocket);	
	return 0;
	
}

