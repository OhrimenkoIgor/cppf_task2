#include "MessageQueue.h"

#include <errno.h>
#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>

//TODO fix exceptions

MessageQueue::MessageQueue(const std::string & queue_name, MessageQueue::Mode mode, int queue_buf_size) :
		name(queue_name), buf_size(queue_buf_size) {

	struct mq_attr attr;
	attr.mq_flags = 0;
	attr.mq_maxmsg = 1;
	attr.mq_msgsize = 1;
	attr.mq_curmsgs = 0;

	std::string mq_name = std::string("/") + name;
	switch (mode) {
	case MessageQueue::Mode::CREATE:
		msgq_id = mq_open(mq_name.c_str(), O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH , 0);
		break;
	case MessageQueue::Mode::OPEN:
		msgq_id = mq_open(mq_name.c_str(), O_RDWR);
		break;
	default:
		//throw "wrong mode";
		printf("wrong mode");
		exit(EXIT_FAILURE);
	}

	if (msgq_id == (mqd_t) -1) {

		printf("mq_open: %s (%d)", strerror(errno), errno);
		exit(EXIT_FAILURE);

		//throw "exception mq_open()";
	}

}

MessageQueue::~MessageQueue() {

	int err = mq_close(msgq_id);


}

std::string MessageQueue::receive_message() {
	std::string ret;

	char buffer[buf_size]; //TODO check \0
	int msgsz = mq_receive(msgq_id, buffer, buf_size, NULL);
	if (msgsz > 0) {
		ret = std::string(buffer);
	} else {

	}

	return ret;
}

void MessageQueue::send_message(const std::string & message) {

	int ret = mq_send(msgq_id, message.c_str(), message.length() + 1, 0);
	if (ret)
		throw "exception mq Failed";

}

