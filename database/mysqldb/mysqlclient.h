#ifndef MYSQLCLIENT_H
#define MYSQLCLIENT_H

#include "../dbclient.h"

class MysqlClient:public DBClient
{
public:
	virtual bool Connect(std::string username, std::string password = "");
	virtual bool Disconnect();
};
#endif