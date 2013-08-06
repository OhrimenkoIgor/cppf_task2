
#ifndef TESTMODULE_H_
#define TESTMODULE_H_

#include "Module.h"
#include "Command.h"

class TestModule: public Module{
	bool state;
	int interval;
	std::string name;
};

class CommandGetState : public Command{
	virtual void parse_arguments(std::string arguments) = 0;

public:
	virtual std::shared_ptr<Command> clone() const {return std::shared_ptr<Command>(new CommandGetState(*this));}
	virtual std::string invoke(std::string arguments) = 0;
	virtual ~Command(){};
};

class CommandGetName : public Command{
	virtual void parse_arguments(std::string arguments) = 0;

public:
	virtual std::shared_ptr<Command> clone() const {return std::shared_ptr<Command>(new CommandGetName(*this));}
	virtual std::string invoke(std::string arguments) = 0;
	virtual ~Command(){};
};

class CommandGetInterval : public Command{
	virtual void parse_arguments(std::string arguments) = 0;

public:
	virtual std::shared_ptr<Command> clone() const {return std::shared_ptr<Command>(new CommandGetInterval(*this));}
	virtual std::string invoke(std::string arguments) = 0;
	virtual ~Command(){};
};

class CommandSetName : public Command{
	virtual void parse_arguments(std::string arguments) = 0;

public:
	virtual std::shared_ptr<Command> clone() const {return std::shared_ptr<Command>(new CommandSetName(*this));}
	virtual std::string invoke(std::string arguments) = 0;
	virtual ~Command(){};
};

class CommandSetInterval : public Command{
	virtual void parse_arguments(std::string arguments) = 0;

public:
	virtual std::shared_ptr<Command> clone() const {return std::shared_ptr<Command>(new CommandSetInterval(*this));}
	virtual std::string invoke(std::string arguments) = 0;
	virtual ~Command(){};
};

#endif /* TESTMODULE_H_ */
