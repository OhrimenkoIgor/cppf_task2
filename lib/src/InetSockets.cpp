
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>

#include "InetSockets.h"

using namespace std;


Connection::Connection(int sockfd_v) : sockfd(sockfd_v) {

}

Connection::Connection(const std::string & serv_hostname, const std::string & serv_port) {

	// TODO exceptions
	struct sockaddr_in serv_addr;
	struct hostent *server;

	int portno = atoi(serv_port.c_str());
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

std::string Connection::read_string() {
	char buffer[BUF_SIZE];
	int n = read(sockfd, buffer, BUF_SIZE);
	if (n < 0)
		throw "ERROR reading from socket";
	std::string ret(buffer);
	return ret;
}

void Connection::write_string(const std::string & s) {
	int n = write(sockfd, s.c_str(), s.length() + 1); //TODO check if +1
	if (n < 0)
		throw "ERROR writing to socket";
}

Server::Server(const std::string & serv_port) {
	// TODO exceptions

	struct sockaddr_in serv_addr;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		throw "ERROR opening socket";
	bzero((char *) &serv_addr, sizeof(serv_addr));
	portno = atoi(serv_port.c_str());
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);
	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
		throw "ERROR on binding";
	listen(sockfd, 5);
}

Server::~Server() {
	close(sockfd);
}

std::shared_ptr<Connection> Server::accept_connection() {
	socklen_t clilen;

	struct sockaddr_in cli_addr;

	clilen = sizeof(cli_addr);
	int newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
	if (newsockfd < 0)
		throw "ERROR on accept";

	std::shared_ptr<Connection> ret(new Connection(newsockfd));
	return ret;
}
