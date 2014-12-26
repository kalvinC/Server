#ifndef KQUEUEMODEL_H
#define KQUEUEMODEL_H


class KQueueModel
{
public:
	typedef enum Socket_Event{
		Event_Read = 0,
		Event_Write
	  }Socket_Event;

	KQueueModel();
	~KQueueModel();

	bool AddEvent(int socket_fd, Socket_Event event);
	bool DeleteEvent(int socket_fd);



private:
	int kqueue_fd;
};
#endif