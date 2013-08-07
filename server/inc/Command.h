
#ifndef COMMAND_H_
#define COMMAND_H_

#include <memory>
#include <string>

class Command{
	virtual void parse_arguments(std::string arguments) = 0;

public:
	virtual std::shared_ptr<Command> clone() const = 0;
	virtual std::string invoke(std::string arguments) = 0;
	virtual ~Command(){};
};


#endif /* COMMAND_H_ */
