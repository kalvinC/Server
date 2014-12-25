#include "tcpserver.h"
#include <string>
#include <errno.h>
#include <unistd.h>
#include <assert.h>


CTcpServer::CTcpServer()
{
	strcpy(this->ip_address,"127.0.0.1");
	this->port = 9000;
	this->server_socket = socket(AF_INET, SOCK_STREAM, 0);
}

CTcpServer::CTcpServer(unsigned short port)
{
	strcpy(this->ip_address, "127.0.0.1");
	this->port = port;
	this->server_socket = socket(AF_INET, SOCK_STREAM, 0);
}

CTcpServer::~CTcpServer()
{
	if(server_socket > 0)
		close(server_socket);
}

bool CTcpServer::Bind()
{
	struct sockaddr_in sockaddress;
	sockaddress.sin_family = AF_INET;
	sockaddress.sin_port = htons(this->port);
	sockaddress.sin_addr.s_addr = inet_addr(this->ip_address);

	int error_rt = bind(server_socket, (struct sockaddr *)&sockaddress, sizeof(struct sockaddr));

	if(error_rt == 0)
		return true;

	printf("%s",strerror(errno));

	return false;
}

bool CTcpServer::Listen()
{
	int error_rt = listen(server_socket, 5);

	if(error_rt == 0)
		return true;

	printf("%s\n", strerror(errno));

	return false;
}

bool CTcpServer::Aceept(int &client_socket, struct sockaddr &client_socket_addr)
{
    int size = sizeof(struct sockaddr);
    client_socket = accept(server_socket, &client_socket_addr, (socklen_t *)&size);
    
    if(client_socket >= 0)
    	return true;

    printf("%s\n", strerror(errno));
	return false;
}

bool CTcpServer::Aceept(int &client_socket)
{
	client_socket = accept(server_socket, NULL, NULL);
	
	if (client_socket >= 0)
		return true;
	
	printf("%s\n", strerror(errno));

	return false;
}

int CTcpServer::SendData(int client_socket, const char * buffer, unsigned int buffer_size)
{
	assert(buffer != NULL);

    int send_size = send(client_socket, buffer, buffer_size, 0);

    if(send_size >= 0)
    	return send_size;

	printf("%s\n", strerror(errno));
	
	return -1;
}

int CTcpServer::RecvData(int client_socket, char * buffer, unsigned int buffer_size)
{
	assert(buffer != NULL);

	int recv_size = recv(client_socket, buffer, buffer_size, 0);

	if(recv_size >= 0)
		return recv_size;

	printf("%s\n", strerror(errno));
	
	return -1;
}