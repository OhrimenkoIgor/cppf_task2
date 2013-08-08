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
		throw InvalidArgumentException(name + " takes no arguments");
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

TestModule::CommandSetParams::CommandSetParams(TestModule * p_tm, const std::string & default_name, int default_interval, const std::string & name_v) :
		TestModuleCommand(p_tm, name_v) {
	params.resize(2);
	params[0].paramName = "name";
	params[0].type = Params::Type::STR;
	params[0].str_val = default_name;
	params[1].paramName = "interval";
	params[1].type = Params::Type::INT;
	params[1].int_val = default_interval;
}

std::string TestModule::CommandSetParams::invoke(const std::string & arguments) {
	try {
		parse_arguments(arguments);
		std::unique_ptr<TestModule::Lock> lock = this->ptm->getLock();
		this->ptm->set_name(params[0].str_val);
		this->ptm->set_interval(params[1].int_val);
		std::stringstream ss;
		ss << "name = " << this->ptm->get_name() << " " << "interval = " << this->ptm->get_interval();
		return ss.str();
	} catch (InvalidArgumentException & ex) {
		return ex.what();
	}
}

