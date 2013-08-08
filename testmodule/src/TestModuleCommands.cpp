#include <sstream>

#include "TestModuleCommands.h"
#include "ModuleExceptions.h"

using std::string;

//TODO

TestModule::CommandGetState::CommandGetState(TestModule * p_tm, const std::string & name_v) :
		TestModuleCommand(p_tm, name_v) {
}

void TestModule::CommandGetState::parse_arguments(const std::string & arguments) {
	if (arguments != "") {
		throw InvalidArgumentException(name + "takes no arguments");
	}
}

std::string TestModule::CommandGetState::invoke(const std::string & arguments) {
	try {
		parse_arguments(arguments);
		std::stringstream ss;
		ss << "state = " << this->ptm->get_state();
		return ss.str();
	} catch (InvalidArgumentException & ex) {
		return ex.what();
	}
}

TestModule::CommandGetParams::CommandGetParams(TestModule * p_tm, const std::string & name_v) :
		TestModuleCommand(p_tm, name_v) {
}

void TestModule::CommandGetParams::parse_arguments(const std::string & arguments) {
	if (arguments != "") {
		throw InvalidArgumentException(name + "takes no arguments");
	}
}

std::string TestModule::CommandGetParams::invoke(const std::string & arguments) {
	try {
		parse_arguments(arguments);
		std::stringstream ss;
		std::unique_ptr<TestModule::Lock> lock = this->ptm->getLock();
		ss << "name = " << this->ptm->get_name() << " " << "interval = " << this->ptm->get_interval();
		return ss.str();
	} catch (InvalidArgumentException & ex) {
		return ex.what();
	}
}

TestModule::CommandSetParams::CommandSetParams(TestModule * p_tm, const std::string & name_v) :
		TestModuleCommand(p_tm, name_v) {
}

void TestModule::CommandSetParams::parse_arguments(const std::string & arguments) {

}

std::string TestModule::CommandSetParams::invoke(const std::string & arguments) {
	try {
		parse_arguments(arguments);
		std::unique_ptr<TestModule::Lock> lock = this->ptm->getLock();
		this->ptm->set_name(name);
		this->ptm->set_interval(interval);
		std::stringstream ss;
		ss << "name = " << this->ptm->get_name() << " " << "interval = " << this->ptm->get_interval();
		return ss.str();
	} catch (InvalidArgumentException & ex) {
		return ex.what();
	}
}

