
#include "ModuleInterface.h"

//TODO fix exceptions

ModuleInterface::ModuleInterface(const std::string & module_name) : IModule(module_name){
	msgq_id = mq_open((std::string("/") + name).c_str(), O_RDWR);
	if (msgq_id == (mqd_t) -1) {
		throw "exception mq_open()";
	}
}

ModuleInterface::~ModuleInterface() {
	mq_close(msgq_id);
}

std::string ModuleInterface::invoke(const std::string & command) {
	using std::string;
	string sret;
	std::unique_ptr<Mutex::Lock> lock = getLock();

	int ret = mq_send(msgq_id, command.c_str(), command.length() + 1, 0);
	if (ret)
		throw "exception mq Failed";
	const int SIZE = 4096;
	char * buffer = new char[SIZE]();
	int msgsz = mq_receive(msgq_id, buffer, SIZE, NULL);
	if (msgsz > 0) {
		sret = string(buffer);
	} else {

	}
	delete[] buffer;

	return sret;
}
