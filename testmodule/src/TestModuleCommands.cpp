
#include "TestModuleCommands.h"

using std::string;

//TODO

TestModule::CommandGetState::CommandGetState(TestModule * p_tm) : TestModuleCommand(p_tm) {}

void TestModule::CommandGetState::parse_arguments(std::string arguments){

}

std::string TestModule::CommandGetState::invoke(std::string arguments){
	string ret;

	return ret;
}

TestModule::CommandGetName::CommandGetName(TestModule * p_tm) : TestModuleCommand(p_tm) {}

void TestModule::CommandGetName::parse_arguments(std::string arguments){

}

std::string TestModule::CommandGetName::invoke(std::string arguments){
	string ret;

	return ret;
}

TestModule::CommandGetInterval::CommandGetInterval(TestModule * p_tm) : TestModuleCommand(p_tm) {}

void TestModule::CommandGetInterval::parse_arguments(std::string arguments){

}

std::string TestModule::CommandGetInterval::invoke(std::string arguments){
	string ret;

	return ret;
}

TestModule::CommandSetName::CommandSetName(TestModule * p_tm) : TestModuleCommand(p_tm) {}

void TestModule::CommandSetName::parse_arguments(std::string arguments){

}

std::string TestModule::CommandSetName::invoke(std::string arguments){
	string ret;

	return ret;
}

TestModule::CommandSetInterval::CommandSetInterval(TestModule * p_tm) : TestModuleCommand(p_tm) {}

void TestModule::CommandSetInterval::parse_arguments(std::string arguments){

}

std::string TestModule::CommandSetInterval::invoke(std::string arguments){
	string ret;

	return ret;
}

