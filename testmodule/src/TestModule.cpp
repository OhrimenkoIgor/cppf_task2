#include <iostream>
#include <unistd.h>

#include "TestModule.h"
#include "TestModuleCommands.h"

void * TestModule::tread_task(void * pthis) {
	TestModule * ptm = reinterpret_cast<TestModule *>(pthis);
	while (ptm->run) {
		sleep(ptm->interval);
		ptm->lock();
		ptm->state = !ptm->state;
		std::cout << ptm->Module::name << " new state is: " << ptm->state << std::endl;
		ptm->unlock();
	}
	pthread_exit(NULL);
}

TestModule::TestModule(bool state_v, int interval_v, const std::string & name_v) :
		Module(name_v), MessageQueue(name_v, MessageQueue::Mode::CREATE), state(state_v), interval(interval_v), run(true) {

	std::shared_ptr<Command> gpc(new CommandGetParams(this, "getparams"));
	std::shared_ptr<Command> spc(new CommandSetParams(this, "testmodule", 1, "setparams"));
	std::shared_ptr<Command> gsc(new CommandGetState(this, "getstate"));
	commands[gpc->get_name()] = gpc;
	commands[spc->get_name()] = spc;
	commands[gsc->get_name()] = gsc;

	int rc = pthread_create(&thread_tm, NULL, TestModule::tread_task, reinterpret_cast<void *>(this));
	if (rc != 0) {
		throw "error pthread_create";
	}
}

TestModule::~TestModule() {
	run = false;
	lock();
	pthread_cancel(thread_tm);
	unlock();
}

void TestModule::set_name(const std::string & new_name) {
	Module::name = new_name;
}
std::string TestModule::get_name() {
	return Module::name;
}
void TestModule::set_interval(int new_interval) {
	interval = new_interval;
}
int TestModule::get_interval() {
	return interval;
}
bool TestModule::get_state() {
	return state;
}
