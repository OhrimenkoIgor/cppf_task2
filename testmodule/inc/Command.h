
#ifndef COMMAND_H_
#define COMMAND_H_

#include <memory>
#include <string>

class Command{
protected:
	std::string  name;
	virtual void parse_arguments(const std::string & arguments) = 0;

public:
	Command(const std::string & name_v = "command"): name(name_v) {}
	virtual std::shared_ptr<Command> clone() const = 0;
	virtual std::string invoke(const std::string & arguments) = 0;
	virtual ~Command(){};
};


#endif /* COMMAND_H_ */
