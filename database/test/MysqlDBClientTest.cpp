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

	std::map<int, std::vector<std::string> >::iterator iter = mysqldbclient.row_val_map.begin();
	for(;iter != mysqldbclient.row_val_map.end(); iter++)
	{
		printf("row num %d:", iter->first);
		for(int i = 0; i < iter->second.size(); i++)
		{
			printf("%s ", iter->second[i].c_str());
		}
		printf("\n");
	}	
	return 0;
}
