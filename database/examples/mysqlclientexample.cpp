#include <stdio.h>
#include "mysql.h"
#include <string>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char * argv[])
{
        MYSQL * mysqlhandle;

        mysqlhandle = mysql_init(NULL);
	
	if(mysqlhandle == NULL)
	{
		fprintf(stderr,"init mysql handler error:%s.");
		exit(1);
	}

	mysql_real_connect(mysqlhandle,"127.0.0.1", "root", NULL, "test", 0, NULL,0);

	if(mysqlhandle == NULL)
	{
		fprintf(stderr, "connect mysql error");
		exit(1);
	}

	std::string test_sql = "select * from login_table";

 	mysql_real_query(mysqlhandle, test_sql.c_str(), test_sql.length());
       
	if(mysqlhandle == NULL)
	{
		fprintf(stderr, "query mysql error");	
		exit(1);
	}

        MYSQL_RES * result;
	
	result = mysql_store_result(mysqlhandle);
	
	if(result == NULL)
	{
		fprintf(stderr, "result error");
		exit(1);
	}
	
	int row_num = mysql_num_rows(result);
	int col_num = mysql_field_count(mysqlhandle);

	MYSQL_FIELD * field = NULL;

	for(int col = 0; col < col_num; col++)
	{
		field = mysql_fetch_field(result);
		printf("--%s--", field->name);
		field = NULL;
	}
	
	printf("\n");

	MYSQL_ROW  row_val;
	for(int i = 0; i < row_num; i++)
	{
		row_val = mysql_fetch_row(result);
		for( int j = 0; j < col_num; j++)
		{
			printf("--%s--", row_val[j]?row_val[j]:NULL); 			
		}
		printf("\n");
	}
	
	mysql_free_result(result);
	mysql_close(mysqlhandle);

	return 0;
}
