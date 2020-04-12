#include <iostream>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include <chrono>


int main(int argc, char ** argv)
{
	if ( argc < 2 )
	{
		std::cout<<"Incorrect usage\nExample usage:-\n./serverMTS.exe <PORT_NUMBER>\n";
		return -1;
	}

	std::cout<<"Booting up server..\n";

	int servSock = socket( AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons( stoi( argv[1] ));
	servAddr.sin_addr.s_addr = INADDR_ANY;

	bind(servSock, (struct sockaddr *) &servAddr, sizeof(servAddr));


	listen(servSock, 10);

	while(1)
	{
		int clientSoc = accept();
	}
	return 0;
}
