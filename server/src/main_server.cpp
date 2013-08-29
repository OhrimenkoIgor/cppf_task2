#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <list>

#include <pthread.h>

#include "InetSockets.h"

#include "AppServer.h"

AppServer appserver;

struct ThreadArg {
	pthread_t thread;
	std::shared_ptr<Connection> con;
	bool done = false;
};

void *TaskCode(void *argument) {
	ThreadArg * pa = reinterpret_cast<ThreadArg *>(argument);

	std::string line;
	std::string ans;

	while (true) {
		line = pa->con->read_string();
		ans = appserver.invoke(line);
		pa->con->write_string(ans);
		if (line == "exit") {
			break;
		}
	}
	pa->done = true;
	pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
	int rc = 0;

	appserver.add_module("testmodule", "/home/ejfori/git/cppf_task2/testmodule/testmodule.elf");

	std::string serv_port;

	if (argc < 2) {
		serv_port = "12345";
	} else {
		serv_port = argv[1];
	}

	Server serv(serv_port);

	std::list<ThreadArg> talist;

	ThreadArg ta;
	pthread_attr_t attr;
	rc = pthread_attr_init(&attr);
	rc = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	for (;;) {
		talist.push_back(ta);
		talist.back().con = serv.accept_connection();
		rc = pthread_create(&(talist.back().thread), &attr, TaskCode, (void *) &talist.back());

		//remove all finished threads. may be in another thread, but list must be locked by mutex. can be map instead list
//		for (auto it = talist.begin(); it != talist.end();) {
//			if (it->done) {
//				rc = pthread_join(it->thread, 0);
//				it = talist.erase(it);
//			} else {
//				++it;
//			}
//		}
		talist.remove_if([](const ThreadArg & ta) {return ta.done;});

	}

	return EXIT_SUCCESS;
}

