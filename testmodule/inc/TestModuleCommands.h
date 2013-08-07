
#ifndef TESTMODULECOMMANDS_H_
#define TESTMODULECOMMANDS_H_

#include <memory>

#include "TestModule.h"

class TestModule::CommandGetState : public TestModuleCommand{
	virtual void parse_arguments(std::string arguments);

public:
	CommandGetState(TestModule * p_tm);
	virtual std::shared_ptr<Command> clone() const {return std::shared_ptr<Command>(new CommandGetState(*this));}
	virtual std::string invoke(std::string arguments);
	virtual ~CommandGetState(){};
};

class TestModule::CommandGetName : public TestModuleCommand{
	virtual void parse_arguments(std::string arguments);

public:
	CommandGetName(TestModule * p_tm);
	virtual std::shared_ptr<Command> clone() const {return std::shared_ptr<Command>(new CommandGetName(*this));}
	virtual std::string invoke(std::string arguments);
	virtual ~CommandGetName(){};
};

class TestModule::CommandGetInterval : public TestModuleCommand{
	virtual void parse_arguments(std::string arguments);

public:
	CommandGetInterval(TestModule * p_tm);
	virtual std::shared_ptr<Command> clone() const {return std::shared_ptr<Command>(new CommandGetInterval(*this));}
	virtual std::string invoke(std::string arguments);
	virtual ~CommandGetInterval(){};
};

class TestModule::CommandSetName : public TestModuleCommand{
	virtual void parse_arguments(std::string arguments);

public:
	CommandSetName(TestModule * p_tm);
	virtual std::shared_ptr<Command> clone() const {return std::shared_ptr<Command>(new CommandSetName(*this));}
	virtual std::string invoke(std::string arguments);
	virtual ~CommandSetName(){};
};

class TestModule::CommandSetInterval : public TestModuleCommand{
	virtual void parse_arguments(std::string arguments);

public:
	CommandSetInterval(TestModule * p_tm);
	virtual std::shared_ptr<Command> clone() const {return std::shared_ptr<Command>(new CommandSetInterval(*this));}
	virtual std::string invoke(std::string arguments);
	virtual ~CommandSetInterval(){};
};

#endif /* TESTMODULECOMMANDS_H_ */
