#include "kqueuemodel.h"
#include "sockconfig.h"
#include <unistd.h>

KQueueModel::KQueueModel()
{
	kqueue_fd = kqueue();
}

KQueueModel::~KQueueModel()
{
	if(kqueue_fd > 0)
		close(kqueue_fd);
}

bool KQueueModel::AddEvent(int socket_fd, Socket_Event event)
{
	return false;
}

bool KQueueModel::DeleteEvent(int socket_fd)
{
	return false;
}