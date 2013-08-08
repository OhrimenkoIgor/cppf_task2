
#ifndef MODULE_H_
#define MODULE_H_

#include <string>

class Module {
public:
	Module();
	~Module();
	std::string invoke(const std::string & command);
};

#endif /* MODULE_H_ */
