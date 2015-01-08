#include "kqueuemodel.h"
#include "sockconfig.h"
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <assert.h>

KQueueModel::KQueueModel()
{
	kqueue_fd = kqueue();

	if(kqueue_fd == -1)
	{
		printf("%s\n", strerror(errno));
	}

	max_event_count = 65532;
}

KQueueModel::KQueueModel(unsigned int max_event_count)
{
	if(max_event_count > 65532)
		this->max_event_count = 65532;

	this->max_event_count = max_event_count;
	kqueue_fd = kqueue();

	if(kqueue_fd == -1)
	{
		printf("%s\n", strerror(errno));
	}
}

KQueueModel::~KQueueModel()
{
	if(kqueue_fd > 0)
		close(kqueue_fd);
}

bool KQueueModel::Register(int socket_fd)
{
	struct kevent kq_event;
	EV_SET(&kq_event, socket_fd, EVFILT_READ, EV_ADD, 0, 0, NULL);

	int ret = kevent(kqueue_fd, &kq_event, 1, NULL, 0, NULL);
	if(ret == 1)
	{
		printf("%s\n", strerror(errno));
		return false;
	}

	return true;
}

bool KQueueModel::UnRegister(int socket_fd)
{
	struct kevent kq_event;
	EV_SET(&kq_event, socket_fd, EVFILT_READ, EV_DELETE, 0, 0, NULL);

	int ret = kevent(kqueue_fd, &kq_event, 1, NULL, 0, NULL);
	if(ret == -1)
	{
		printf("%s\n", strerror(errno));
		return false;
	}

	return true;
}

int KQueueModel::EventResponseList(struct kevent * kevent_list)
{
	assert(kevent_list != NULL);

	int ret = kevent(kqueue_fd, NULL, 0 , kevent_list, max_event_count, NULL);
	
	if(ret == -1)
	{
		printf("%s\n", strerror(errno));
	}
	
	return ret;
}