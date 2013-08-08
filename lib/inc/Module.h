
#ifndef MODULE_H_
#define MODULE_H_

#include <map>
#include <memory>

#include "IModule.h"
#include "Command.h"

class Module : public IModule {
protected:
	std::map<std::string, std::shared_ptr<Command> > commands;

public:
	Module(const std::string & module_name) : IModule(module_name) {}
	virtual std::string invoke(const std::string & command);
	virtual ~Module(){}
};

#endif /* MODULE_H_ */
