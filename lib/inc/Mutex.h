
#ifndef MUTEX_H_
#define MUTEX_H_

#include <memory>
#include <pthread.h>

class Mutex {
	pthread_mutex_t mutex_tm;

public:
	Mutex();
	~Mutex();

	void lock();
	void unlock();

	class Lock {
		friend class Mutex;
		Mutex * pmutex;
		Lock(Mutex * m);
	public:
		~Lock();
	};

	std::unique_ptr<Mutex::Lock> getLock();
};

#endif /* MUTEX_H_ */
