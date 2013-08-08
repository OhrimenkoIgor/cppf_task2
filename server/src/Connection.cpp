
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "Connection.h"

Connection::Connection(int sockfd_v) : sockfd(sockfd_v) {

}

Connection::~Connection() {
	close(sockfd);
}

std::string Connection::read_string() {
	const int SIZE = 4096;
	char * buffer = new char [SIZE];
	int n = read(sockfd, buffer, SIZE);
	if (n < 0)
		throw "ERROR reading from socket";
	std::string ret(buffer);
	delete[] buffer;
	return ret;
}

void Connection::write_string(const std::string & s) {
	int n = write(sockfd, s.c_str(), s.length() + 1); //TODO check if +1
	if (n < 0)
		throw "ERROR writing to socket";
}
