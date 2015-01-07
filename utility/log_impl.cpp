#include "log.h"
#include <time.h>

Log::Log(std::string log_path)
{
	outputLogStream.open(log_path.c_str(),std::ios::out | std::ios::app);
}

Log::~Log()
{
	outputLogStream.close();
}

void Log::OutputLog(enum Log_Event log_event, std::string log_content)
{
	mt_lock.Lock();
	outputLogStream<<log_event;
	outputLogStream<<outputLogStream.fill(' ');
	outputLogStream<<log_content;
	outputLogStream<<outputLogStream.fill(' ');

	time_t timer;
	time(&timer);
	char timebuf[80];
	struct tm * ltm = localtime(&timer);
    strftime(timebuf, 80,"%Y/%m/%d %H:%M:%S", ltm);

    outputLogStream<<timebuf;
	outputLogStream<<"\n";
	mt_lock.UnLock();
}