#ifndef __MYSQLDBCLIENT_H_
#define __MYSQLDBCLIENT_H_
#include "DBClient.h"
#include "mysql.h"

#include <map>
#include <vector>
#include <string>

class MysqlDBClient:public DBClient
{
public:
	MysqlDBClient();
	~MysqlDBClient();

	virtual bool Connect(char * ip, unsigned short port, char * user = NULL, char * password = NULL, char * db = NULL);
	virtual bool Disconnect();
	virtual bool ExecuteSql(char * sql, int argc = 0, char * argv = NULL);

private:
	char * ip;
	char * user;
	char * password;
	char * db;
	unsigned short port;

	MYSQL * mysqlhandle;
	
	std::vector<std::string> col_name_vector;
        std::map<int, std::vector<std::string> > row_val_map;
};

#endif
