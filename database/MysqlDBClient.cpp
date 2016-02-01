#include "MysqlDBClient.h"
#include <assert.h>
#include <string.h>

MysqlDBClient::MysqlDBClient()
{
	mysqlhandle = mysql_init(NULL);
}

MysqlDBClient::~MysqlDBClient()
{
	mysql_close(mysqlhandle);
	mysqlhandle = NULL;
}

bool MysqlDBClient::Connect(char * ip, unsigned short port, char * user = NULL, char * password = NULL, char * db = NULL) 
{
	assert(ip == NULL);
	this->ip = ip;
	this->port = port;
	this->user = user;
	this->password = password;
	this->db = db;
	
	return (mysql_real_connect(mysqlhandle, this->ip, this->user, this->password, this->db, this->port, NULL, 0) != NULL); 
}

bool MysqlDBClient::Disconnect()
{
	return true;
}

bool MysqlDBClient::ExecuteSql(char * sql, int argc, char * argv)
{
	assert(sql != NULL);	

	MYSQL_RES * result;
	if(argc == 0)
	{
		mysql_real_query(mysqlhandle, sql, strlen(sql));
	}	
	
	result = mysql_store_result(mysqlhandle);
	
	if(result == NULL)
	{
		return false;
	}

	int col_num = mysql_field_count(mysqlhandle);
	int row_num = mysql_num_rows(result);
	
	col_name_vector.clear();
	MYSQL_FIELD * field = NULL;
	for(int col = 0; col < col_num; col++)
	{
		field = mysql_fetch_field(result);
		col_name_vector.push_back(field->name);
		field = NULL;
	}

	MYSQL_ROW row_val;
	for(int i=0; i < row_num; i++)
	{
                std::vector<std::string> row_val_vector;

		row_val = mysql_fetch_row(result);
		for(int j = 0; j < row_num; j++)
		{
			row_val_vector.push_back(row_val[j]);
		}
		row_val_map.insert(std::pair<int, std::vector<std::string> >(i, row_val_vector));
	}
	
	mysql_free_result(result);

	return true;
}
