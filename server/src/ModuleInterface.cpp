
#include <sys/types.h>
#include <sys/wait.h>

#include "ModuleInterface.h"

ModuleInterface::ModuleInterface(const std::string & module_name, pid_t module_pid) : IModule(module_name), MessageQueue(module_name, MessageQueue::Mode::OPEN, 8192), pid(module_pid){

}

ModuleInterface::~ModuleInterface() {
	waitpid(pid, 0, 0);
}

std::string ModuleInterface::invoke(const std::string & command) {
	using std::string;
	std::unique_ptr<Mutex::Lock> lock = getLock();
	send_message(command);
	return receive_message();
}
