#ifndef __MYSQLDBCLIENT_H_
#define __MYSQLDBCLIENT_H_
#include "DBClient.h"

class MysqlDBClient:public DBClient
{
public:
	MysqlDBClient();
	~MysqlDBClient();
 	
	virtual bool Connect(char * ip, char * user = NULL, char * password = NULL);
	virtual bool Disconnect();
	virtual bool ExecuteSql(char * sql, int argc = 0, char * argv = NULL);
private:
	bool Reconnect();

private:
	char * ip;
	char * user;
	char * password;

	MSYQL * mysqlhandle;
};

#endif
