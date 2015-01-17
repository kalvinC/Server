#ifndef THREADPOOL_H
#define THREADPOOL_H
#include <pthread.h>
#include <list>
/**

管理线程池
1. 初始化线程池
2. 释放线程池资源
3. 任务分配
*/

template<class T, int size>
class ThreadPool
{
public:
	ThreadPool();
	~ThreadPool();

	void process_data();
	void initialize_pool();
	void release_pool();

private:
	pthread_t threadpool[size];
};

template<class T, int size>
ThreadPool<T,size>::ThreadPool()
{

}

template<class T, int size>
ThreadPool<T, size>::~ThreadPool()
{

}

template<class T, int size>
void ThreadPool<T,size>::process_data()
{

}

template<class T, int size>
void ThreadPool<T, size>::initialize_pool()
{

}

template<class T, int size>
void ThreadPool<T, size>::release_pool()
{

}
#endif