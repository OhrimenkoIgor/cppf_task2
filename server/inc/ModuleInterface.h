
#ifndef MODULEINTERFACE_H_
#define MODULEINTERFACE_H_

#include <string>

#include <unistd.h>

#include "IModule.h"
#include "Mutex.h"
#include "MessageQueue.h"

class ModuleInterface : public IModule, public Mutex, public MessageQueue {
	 pid_t pid;
public:
	ModuleInterface(const std::string & module_name, pid_t module_pid);
	~ModuleInterface();
	std::string invoke(const std::string & command);
};

#endif /* MODULEINTERFACE_H_ */
