
#ifndef APPSERVER_H_
#define APPSERVER_H_

#include <map>
#include <string>
#include <memory>

#include "ModuleInterface.h"

class AppServer{

	std::map<std::string, std::shared_ptr<ModuleInterface> > modules;

public:

	AppServer();

	void add_module(const std::string & name, const std::string & path);

	std::string invoke(const std::string & module_command);
};

#endif /* APPSERVER_H_ */
