
#include <iostream>
#include <unistd.h>

#include "TestModule.h"

void * TestModule::tread_task(void * pthis){
	TestModule * ptm = reinterpret_cast<TestModule *>(pthis);
	while (ptm->run) {
		sleep(ptm->interval);
		pthread_mutex_lock (&ptm->mutex_tm);
		ptm->state = !ptm->state;
		std::cout << ptm->name << " new state is: " << ptm->state << std::endl;
		pthread_mutex_unlock (&ptm->mutex_tm);
	}
	pthread_exit(NULL);
}

TestModule::TestModule(bool state_v, int interval_v, const std::string & name_v) : state(state_v), interval(interval_v), name(name_v), run(true) {
	 pthread_mutex_init(&mutex_tm, NULL);
	 int rc = pthread_create(&thread_tm, NULL, TestModule::tread_task, reinterpret_cast<void *>(this));
	 if(rc != 0){
		 pthread_mutex_destroy(&mutex_tm);
		 throw "error pthread_create";
	 }
}

TestModule::~TestModule(){
	run = false;
	pthread_mutex_lock (&mutex_tm);
	pthread_cancel(thread_tm);
	pthread_mutex_unlock (&mutex_tm);
	pthread_mutex_destroy(&mutex_tm);
}

void TestModule::set_name(const std::string & new_name) {
	name = new_name;
}
std::string TestModule::get_name() {
	return name;
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

void TestModule::lock(){
	pthread_mutex_lock (&mutex_tm);
}

void TestModule::unlock(){
	pthread_mutex_unlock (&mutex_tm);
}

TestModule::Lock::Lock(TestModule * ptmv) : ptm(ptmv) {
	ptm->lock();
}

TestModule::Lock::~Lock(){
	ptm->unlock();
}

std::unique_ptr<TestModule::Lock> TestModule::getLock(){
	return std::unique_ptr<TestModule::Lock>(new TestModule::Lock(this));
}
