
#ifndef MODULEINTERFACE_H_
#define MODULEINTERFACE_H_

#include <string>

#include "IModule.h"
#include "Mutex.h"
#include "MessageQueue.h"

class ModuleInterface : public IModule, public Mutex, public MessageQueue {
public:
	ModuleInterface(const std::string & module_name);
	~ModuleInterface();
	std::string invoke(const std::string & command);
};

#endif /* MODULEINTERFACE_H_ */
