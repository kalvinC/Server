#include "mutexlock.h"

CMutexLock::CMutexLock()
{
	pthread_mutex_init(&mt_lock, NULL);
}

CMutexLock::~CMutexLock()
{
	pthread_mutex_destroy(&mt_lock);
}

void CMutexLock::Lock()
{
	pthread_mutex_lock(&mt_lock);
}

void CMutexLock::UnLock()
{
	pthread_mutex_unlock(&mt_lock);
}