#ifndef MUTEXTLOCK_H
#define MUTEXTLOCK_H

#include <pthread.h>

class CMutexLock
{
public:
	CMutexLock();
	~CMutexLock();

	void Lock();
	void UnLock();
private:
	pthread_mutex_t mt_lock;
};
#endif