
#include <string>

#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

#include "Connection.h"

using namespace std;

Connection::Connection(const std::string & serv_hostname, const std::string & serv_port) {

	struct sockaddr_in serv_addr;
	struct hostent *server;

	portno = atoi(serv_port.c_str());
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		throw "ERROR opening socket";
	server = gethostbyname(serv_hostname.c_str());
	if (server == NULL) {
		throw "ERROR, no such host\n";
	}
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr,	server->h_length);
	serv_addr.sin_port = htons(portno);
	if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
		throw "ERROR connecting";

}

Connection::~Connection() {
	close(sockfd);
}

std::string Connection::command(const std::string & com) {

	const int SIZE = 4096;
	char * buffer = new char [SIZE]();

	int n;
	n = write(sockfd, com.c_str(), com.size() + 1);
	if (n < 0)
		throw "ERROR writing to socket";
	n = read(sockfd, buffer, SIZE);
	if (n < 0)
		throw "ERROR reading from socket";

	std::string ret(buffer);

	delete [] buffer;

	return ret;
}
