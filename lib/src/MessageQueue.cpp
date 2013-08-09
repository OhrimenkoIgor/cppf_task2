#include "MessageQueue.h"

//TODO fix exceptions

MessageQueue::MessageQueue(const std::string & queue_name, MessageQueue::Mode mode) :
		name(queue_name) {

	switch (mode) {
	case MessageQueue::Mode::CREATE:
		msgq_id = mq_open((std::string("/") + name).c_str(), O_RDWR | O_CREAT | O_EXCL);
		break;
	case MessageQueue::Mode::OPEN:
		msgq_id = mq_open((std::string("/") + name).c_str(), O_RDWR);
		break;
	default:
		throw "wrong mode";
	}

	if (msgq_id == (mqd_t) -1) {
		throw "exception mq_open()";
	}
}

MessageQueue::~MessageQueue() {
	mq_close(msgq_id);
}

std::string MessageQueue::receive_message() {
	const int SIZE = 4096;
	std::string ret;
	char * buffer = new char[SIZE]();
	int msgsz = mq_receive(msgq_id, buffer, SIZE, NULL);
	if (msgsz > 0) {
		ret = std::string(buffer);
	} else {

	}
	delete[] buffer;
	return ret;
}

void MessageQueue::send_message(const std::string & message) {
	int ret = mq_send(msgq_id, message.c_str(), message.length() + 1, 0);
	if (ret)
		throw "exception mq Failed";
}

