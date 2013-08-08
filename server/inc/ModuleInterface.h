
#ifndef MODULEINTERFACE_H_
#define MODULEINTERFACE_H_

#include <string>

#include <mqueue.h>
#include <pthread.h>

#include "IModule.h"
#include "Mutex.h"

class ModuleInterface : public IModule, public Mutex {
private:
	mqd_t msgq_id;
public:
	ModuleInterface(const std::string & module_name);
	~ModuleInterface();
	std::string invoke(const std::string & command);
};

#endif /* MODULEINTERFACE_H_ */
