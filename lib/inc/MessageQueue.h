
#ifndef MESSAGEQUEUE_H_
#define MESSAGEQUEUE_H_

#include <string>

#include <mqueue.h>

class MessageQueue {
	mqd_t msgq_id;
	std::string name;
public:

	enum class Mode{
		CREATE,
		OPEN
	};

	MessageQueue(const std::string & queue_name, MessageQueue::Mode mode);
	~MessageQueue();

	std::string receive_message();
	void send_message(const std::string & message);
};

#endif /* MESSAGEQUEUE_H_ */
