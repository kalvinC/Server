#include <stdio.h>
#include "communication/tcpserver.h"

int main(int argc, char const *argv[])
{
	CTcpServer * tcpserver = new CTcpServer();
	if(tcpserver->SetNonBlocking())
		printf("%s\n", "true" );
	else
		return 1;
	if(tcpserver->Bind())
	{
		if(tcpserver->Listen())
		{
			int client_socket;
			while(tcpserver->Aceept(client_socket))
			{
				char buffer[1024];
				if(tcpserver->RecvData(client_socket,buffer,1024))
				{
					printf("%s\n", buffer);
				}
				printf("%s\n","ok");
			}
		}
	}
    delete tcpserver;
	printf("%s\n", "hello world!");
	return 0;
}