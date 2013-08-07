
#ifndef SERVER_H_
#define SERVER_H_

#include <memory>

#include "Connection.h"

class Server {
	int sockfd;
	int portno;
public:
	Server(std::string serv_port);
	std::shared_ptr<Connection> accept_connection();
	~Server();
};

#endif /* SERVER_H_ */
