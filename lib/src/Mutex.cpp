#include "Mutex.h"

Mutex::Mutex() {
	pthread_mutex_init(&mutex_tm, NULL);
}

Mutex::~Mutex() {
	pthread_mutex_destroy(&mutex_tm);
}

void Mutex::lock() {
	pthread_mutex_lock(&mutex_tm);
}

void Mutex::unlock() {
	pthread_mutex_unlock(&mutex_tm);
}

Mutex::Lock::Lock(Mutex * m) :
		pmutex(m) {
	pmutex->lock();
}

Mutex::Lock::~Lock() {
	pmutex->unlock();
}

std::unique_ptr<Mutex::Lock> Mutex::getLock() {
	return std::unique_ptr < Mutex::Lock > (new Mutex::Lock(this));
}
