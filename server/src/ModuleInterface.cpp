
#include "ModuleInterface.h"

ModuleInterface::ModuleInterface(const std::string & module_name) : IModule(module_name), MessageQueue(module_name, MessageQueue::Mode::OPEN){

}

ModuleInterface::~ModuleInterface() {

}

std::string ModuleInterface::invoke(const std::string & command) {
	using std::string;
	std::unique_ptr<Mutex::Lock> lock = getLock();
	send_message(command);
	return receive_message();
}
