/**
log for record event log. 
event:
event_id event_description event_time
*/
#ifndef LOG_H
#define LOG_H
#include <string>
#include <fstream>
#include "mutexlock.h"

class Log
{
public:
	enum Log_Event{
		log_socket_error = 1
	};

	Log(std::string log_path);
	~Log();

	void OutputLog(enum Log_Event log_event, std::string log_content);

private:
	std::ofstream outputLogStream;
	CMutexLock mt_lock;

};

#endif