#include "MysqlDBClient.h"

MysqlDBClient::MysqlDBClient()
{

}

MysqlDBClient::~MysqlDBClient()
{

}

bool MysqlDBClient::Connect(char * ip, char * user, char * password)
{
	return false;
}

bool MysqlDBClient::Disconnect()
{
	return false;
}

bool MysqlDBClient::ExecuteSql(char * sql, int argc, char * argv)
{
	return false;
}
