#ifndef CSINGLETON_H
#define CSINGLETON_H

#include "mutexlock.h"
template<class T>
class CSingleton
{
public:
	static T * GetInstance();
private:
	static T * instance;

	static CMutexLock mtLock;
    
    CSingleton(){}
};

template<class T>
T * CSingleton<T>::instance = NULL;

template<class T>
T * CSingleton<T>::GetInstance()
{
	if(instance == NULL)
	{
		mtLock.Lock();
		if(instance == NULL)
			instance = new T();
		mtLock.UnLock();
	}
	return instance;
}
#endif