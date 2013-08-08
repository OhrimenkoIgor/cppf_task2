
#ifndef IMODULE_H_
#define IMODULE_H_

#include <string>

class IModule {
protected:
	std::string name;

public:
	IModule(const std::string & module_name) : name(module_name) {}
	virtual std::string invoke(const std::string & command) = 0;
	virtual ~IModule(){}
};

#endif /* IMODULE_H_ */
