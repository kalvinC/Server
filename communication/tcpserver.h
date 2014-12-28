#ifndef TCPSERVER_H
#define TCPSERVER_H

#include "sockconfig.h"

class CTcpServer
{
public:
	CTcpServer();
	CTcpServer(unsigned short port);
	~CTcpServer();

public:
	/**
	@return if set success, true, else false.
	*/
	bool SetNonBlocking();
	
	/**
	@brief wrapper the bind function of socket.The ip address
	is 127.0.0.1 and the default port is 9000.
	@return if bind successful, return true, else false.
	*/
	bool Bind();
	/**
	@brief default listen 5.
	@return if listen succussful, return true.else false.
	*/
	bool Listen();
	/**
	@brief wrapper the function accept of socket, and accept return the connecting 
	client socekt and client address.
	@param[out] client_socket
	@param[out] client_socket_addr
	@return if has the client connecting to, true else false.
	*/
	bool Aceept(int & client_socket, struct sockaddr &client_socket_addr);
	/**
	@brief wrapper the function accept, and just return client socket.
	@param[out] client_socket.
	@return if has the client connecting to, true else false.
	*/
	bool Aceept(int & client_socket);
	/**
    @brief send data to client.
    @param[in] client_socket client socket.
    @param[in] buffer data need to be sent.
    @param[in] buffer_size how much data need to be sent.
    @return how much data has been sent successfully.
	*/
	int SendData(int client_socket, const char * buffer, unsigned int buffer_size);
	/**
	@breif recv data from client socket.
	@param[in] client_socket client socket.
	@param[out] buffer store data from client socket.
	@param[in] buffer_size size of buffer.
	@return how much data has been recieve successfully. 
	*/
	int RecvData(int client_socket, char * buffer, unsigned int buffer_size);

private:
	char ip_address[16];
	unsigned short port;
	int server_socket;




};
#endif 