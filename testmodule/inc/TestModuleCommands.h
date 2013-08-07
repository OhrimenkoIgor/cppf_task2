
#ifndef TESTMODULECOMMANDS_H_
#define TESTMODULECOMMANDS_H_

#include <memory>

#include "TestModule.h"

class TestModule::CommandGetState : public TestModuleCommand{
	virtual void parse_arguments(std::string arguments);

public:
	CommandGetState(TestModule * p_tm, const std::string & name_v = "getstate");
	virtual std::shared_ptr<Command> clone() const {return std::shared_ptr<Command>(new CommandGetState(*this));}
	virtual std::string invoke(std::string arguments);
	virtual ~CommandGetState(){};
};

class TestModule::CommandGetParams : public TestModuleCommand{
	virtual void parse_arguments(std::string arguments);

public:
	CommandGetParams(TestModule * p_tm, const std::string & name_v = "getparams");
	virtual std::shared_ptr<Command> clone() const {return std::shared_ptr<Command>(new CommandGetParams(*this));}
	virtual std::string invoke(std::string arguments);
	virtual ~CommandGetParams(){};
};

class TestModule::CommandSetParams : public TestModuleCommand{
	virtual void parse_arguments(std::string arguments);

public:
	CommandSetParams(TestModule * p_tm, const std::string & name_v = "setparams");
	virtual std::shared_ptr<Command> clone() const {return std::shared_ptr<Command>(new CommandSetParams(*this));}
	virtual std::string invoke(std::string arguments);
	virtual ~CommandSetParams(){};
};

#endif /* TESTMODULECOMMANDS_H_ */
