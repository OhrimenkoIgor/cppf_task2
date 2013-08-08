
#ifndef MODULE_H_
#define MODULE_H_

#include <map>
#include <memory>

#include "Command.h"

class Module {
protected:
	std::string name;
	std::map<std::string, std::shared_ptr<Command> > commands;

public:
	Module(const std::string & module_name) : name(module_name) {}
	std::string invoke(const std::string & command);
	virtual ~Module(){}
};

#endif /* MODULE_H_ */
