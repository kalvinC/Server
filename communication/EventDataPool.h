#ifndef EVENTDATAPOOL_H
#define EVENTDATAPOOL_H

#include <list>
#include "../utility/mutexlock.h"

template<class T>
class CEventDataPool
{
public:
	CEventDataPool();
	~CEventDataPool();

    /**
    *@ param[in] val
    *@ return if add successfully, true else false.
    */
	bool AddItem(T val);

	/**
	*@ brief: get the first itme of list.
	*@ param[out] val
	*@ return if successfully, true else false.
	*/
	bool GetItem(T & val);

	/**
	*@brief: estimate whether the list is empty or not.
	*@return true or false.
	*/
	bool Empty();

	/**
	*@brief: clear the pool.
	*/
	void Clear();

	/**
    *@return size of list 
	*/
	unsigned int Size();

private:
	std::list<T> data_list;
	CMutexLock mt_lock;
	unsigned int max_list_size;

};

template<class T>
CEventDataPool<T>::CEventDataPool()
{
	max_list_size = 10000;
}

template<class T>
CEventDataPool<T>::~CEventDataPool()
{

}

template<class T>
bool CEventDataPool<T>::AddItem(T val)
{
	mt_lock.Lock();
	
	if(data_list.size() >= max_list_size)
	{
		mt_lock.UnLock();
		return false;
	}	
	
	data_list.push_back(val);
	
	mt_lock.UnLock();

	return true;

}

template<class T>
bool CEventDataPool<T>::GetItem(T & val)
{
	mt_lock.Lock();

	if(data_list.size() <= 0)
	{
		mt_lock.UnLock();
		return false;
	}	

	val = data_list.front();
	data_list.pop_front();

	mt_lock.UnLock();

	return true;
}

template<class T>
bool CEventDataPool<T>::Empty()
{
	return data_list.empty();
}

template<class T>
void CEventDataPool<T>::Clear()
{
	mt_lock.Lock();

	data_list.clear();
	
	mt_lock.UnLock();
}

template<class T>
unsigned int CEventDataPool<T>::Size()
{
	return data_list.size();
}

#endif