

#ifndef MODULE_H_
#define MODULE_H_

#include <map>
#include <memory>

#include "Command.h"

class Module{

	std::map<std::string, std::shared_ptr<Command> > commands;

public:

	std::string invoke(const std::string & command);

};


#endif /* MODULE_H_ */
