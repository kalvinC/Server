#ifndef DBCLIENT_H
#define DBCLIENT_H

#include <string>


class DBClient
{
 public:
   virtual bool Connect(std::string username, std::string password = "") = 0;
   virtual bool Disconnect() = 0;
};
#endif 
