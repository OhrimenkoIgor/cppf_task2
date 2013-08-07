
#ifndef TESTMODULECOMMANDS_H_
#define TESTMODULECOMMANDS_H_

#include <memory>

#include "TestModule.h"

class TestModule::CommandGetState : public Command{
	virtual void parse_arguments(std::string arguments);

public:
	virtual std::shared_ptr<Command> clone() const {return std::shared_ptr<Command>(new CommandGetState(*this));}
	virtual std::string invoke(std::string arguments);
	virtual ~CommandGetState(){};
};

class TestModule::CommandGetName : public Command{
	virtual void parse_arguments(std::string arguments);

public:
	virtual std::shared_ptr<Command> clone() const {return std::shared_ptr<Command>(new CommandGetName(*this));}
	virtual std::string invoke(std::string arguments);
	virtual ~CommandGetName(){};
};

class TestModule::CommandGetInterval : public Command{
	virtual void parse_arguments(std::string arguments);

public:
	virtual std::shared_ptr<Command> clone() const {return std::shared_ptr<Command>(new CommandGetInterval(*this));}
	virtual std::string invoke(std::string arguments);
	virtual ~CommandGetInterval(){};
};

class TestModule::CommandSetName : public Command{
	virtual void parse_arguments(std::string arguments);

public:
	virtual std::shared_ptr<Command> clone() const {return std::shared_ptr<Command>(new CommandSetName(*this));}
	virtual std::string invoke(std::string arguments);
	virtual ~CommandSetName(){};
};

class TestModule::CommandSetInterval : public Command{
	virtual void parse_arguments(std::string arguments);

public:
	virtual std::shared_ptr<Command> clone() const {return std::shared_ptr<Command>(new CommandSetInterval(*this));}
	virtual std::string invoke(std::string arguments);
	virtual ~CommandSetInterval(){};
};

#endif /* TESTMODULECOMMANDS_H_ */
