
#ifndef TESTMODULE_H_
#define TESTMODULE_H_

#include "Module.h"
#include "Command.h"

class TestModule: public Module{
	class CommandGetState;
	class CommandGetName;
	class CommandGetInterval;
	class CommandSetName;
	class CommandSetInterval;

	bool state;
	int interval;
	std::string name;
};

#endif /* TESTMODULE_H_ */
