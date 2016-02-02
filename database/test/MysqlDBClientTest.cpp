#include "MysqlDBClient.h"

#include <stdio.h>

int main()
{
	MysqlDBClient mysqldbclient;
	mysqldbclient.Connect("127.0.0.1",0,"root",NULL,"test");
	
	const char * sql = "select * from login_table";
	if(mysqldbclient.ExecuteSql(sql) == false)
		printf("error\n");
	
        for(int i =0; i < mysqldbclient.col_name_vector.size(); i++)
	{
		printf("%s\n", mysqldbclient.col_name_vector[i].c_str());
	}		
	return 0;
}
