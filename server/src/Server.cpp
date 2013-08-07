
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "Server.h"

Server::Server(std::string serv_port) {
	// TODO Auto-generated constructor stub

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
