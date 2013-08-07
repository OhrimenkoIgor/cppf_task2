
#include "TestModuleCommands.h"

using std::string;

//TODO

TestModule::CommandGetState::CommandGetState(TestModule * p_tm, const std::string & name_v) : TestModuleCommand(p_tm, name_v) {}

void TestModule::CommandGetState::parse_arguments(std::string arguments){

}

std::string TestModule::CommandGetState::invoke(std::string arguments){
	string ret;

	return ret;
}

TestModule::CommandGetParams::CommandGetParams(TestModule * p_tm, const std::string & name_v) : TestModuleCommand(p_tm, name_v) {}

void TestModule::CommandGetParams::parse_arguments(std::string arguments){

}

std::string TestModule::CommandGetParams::invoke(std::string arguments){
	string ret;

	return ret;
}


TestModule::CommandSetParams::CommandSetParams(TestModule * p_tm, const std::string & name_v) : TestModuleCommand(p_tm, name_v) {}

void TestModule::CommandSetParams::parse_arguments(std::string arguments){

}

std::string TestModule::CommandSetParams::invoke(std::string arguments){
	string ret;

	return ret;
}

