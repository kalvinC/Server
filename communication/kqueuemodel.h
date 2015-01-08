#ifndef KQUEUEMODEL_H
#define KQUEUEMODEL_H


class KQueueModel
{
public:
	/**
	* As know, the max count of socket is 65532, so we set the max event count 65532.
	* when you construct a kqueuemodel with a count parameter, if the count is over 65532, 
	* the max event count will be set to 65532.
	*/
	KQueueModel();
	KQueueModel(unsigned int max_event_count);
	~KQueueModel();

    /**
    *@brief register socket on kqueue.And we mainly focus the read event.
    *@param[in] socket id 
    *@return if register socket on kqueue successfully, true else false.
    */
    bool Register(int socket_fd);
    /**
    *@brief unregister socket on kqueue. And we mainly focus the read event.
    *@param[in] socket id 
    *@return if unregister socket on kqueue successfully, true else false.
    */
    bool UnRegister(int socekt_fd);

    /**
    *@brief get the response list on kqueue.
    *@param[out] kevent_list kevent list
    *@return the number of response kevent on kqueue. 
    */
    int EventResponseList(struct kevent * kevent_list);

private:
	int kqueue_fd;/* kqueue id*/
	unsigned int max_event_count; /* the max kevent count*/
};
#endif