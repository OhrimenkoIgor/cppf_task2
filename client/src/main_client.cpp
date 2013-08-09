#include <iostream>
#include <string>
#include <cstdlib>

#include "Connection.h"

using namespace std;

int main(int argc, char *argv[]) {
	string serv_hostname, serv_port;

	if (argc < 3) {
		serv_hostname = "127.0.0.1";
		serv_port = "12345";
	} else {
		serv_hostname = argv[1];
		serv_port = argv[2];
	}

	string line;

	Connection con(serv_hostname, serv_port);

	while (true) {
		cout << endl << ">";
		getline(cin, line);
		cout << con.command(line);
		if (line == "exit") {
			break;
		}
	}

	return EXIT_SUCCESS;
}


/*
#include "MessageQueue.h"

int main(int argc, char *argv[]) {

	MessageQueue mq("testmodule", MessageQueue::Mode::OPEN);

	string line;

	while (true) {
		cout << endl << ">";
		getline(cin, line);
		mq.send_message(line);
		cout << mq.receive_message();
		if (line == "exit") {
			break;
		}
	}

	return EXIT_SUCCESS;
}

*/
