#ifndef SQLLITE_H
#define SQLLITE_H

#include "../dbclient.h"

class SqlLiteClient:public DBClient
{
public:
	virtual bool Connect(std::string username, std::string password = "");
	virtual bool Disconnect();

};
#endif