#ifndef __DBCLIENT_H_
#define __DBCLIENT_H_

#include <stdio.h>

class DBClient
{
public:
	/**
 	* Connect function
 	* help you connect to database, you should set ip, user, password.
 	* */ 	
	virtual bool Connect(char * ip, char * user = NULL, char * password = NULL) = 0;
        /**
  	* Disconnect to database.
  	* 
  	**/
	virtual bool Disconnect() = 0;
        /**
  	* execute sql.
  	* 	
        **/
	virtual bool ExecuteSql(char * sql, int argc = 0, char * argv = NULL) = 0;
        /**
 	* Deconstruct function.
 	* Must be a empty function, or the child class's deconstruct function will not be called.
 	* */ 
	virtual ~DBClient(){};
};
#endif
