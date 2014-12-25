#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

class CTcpServer
{
public:
	CTcpServer();
	CTcpServer(unsigned short port);
	~CTcpServer();

public:
	bool Bind();
	bool Listen();
	bool Aceept(int & client_socket, struct sockaddr &client_socket_addr);
	bool Aceept(int & client_socket);
	int SendData(int client_socket, const char * buffer, unsigned int buffer_size);
	int RecvData(int client_socket, char * buffer, unsigned int buffer_size);

private:
	char ip_address[16];
	unsigned short port;
	int server_socket;




};
#endif 