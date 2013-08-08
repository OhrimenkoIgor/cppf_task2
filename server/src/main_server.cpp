#include <stdio.h>
#include <stdlib.h>
#include <string>

#include <pthread.h>

#include "Server.h"

struct ThreadArg {
	pthread_t thread;
	std::shared_ptr<Connection> con;
};

void *TaskCode(void *argument) {
	ThreadArg * pa = reinterpret_cast<ThreadArg *>(argument);

	std::string line;
	while (true) {
		line = pa->con->read_string();
		if (line == "exit") {
			pa->con->write_string(line);
			break;
		}
		//TODO
		pa->con->write_string(line);
	}

	pthread_exit(NULL);
}

int main(int argc, char *argv[]) {

	std::string serv_port;

	if (argc < 2) {
		serv_port = "12345";
	} else {
		serv_port = argv[1];
	}

	Server serv(serv_port);

	ThreadArg ta[3];

	//TODO change connection number
	for (int i = 0; i < 3; i++) {
		ta[i].con = serv.accept_connection();
		int rc = pthread_create(&ta[i].thread, NULL, TaskCode, (void *) &ta[i]);
	}

	for (int i = 0; i < 3; ++i) {
		int rc = pthread_join(ta[i].thread, NULL);
	}

	return EXIT_SUCCESS;
}

