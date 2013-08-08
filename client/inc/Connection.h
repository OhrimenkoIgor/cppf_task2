
#ifndef CONNECTION_H_
#define CONNECTION_H_

#include <string>

class Connection {
	int sockfd;
	int portno;
public:
	Connection(const std::string & serv_hostname = "127.0.0.1", const std::string & serv_port = "12345");

	std::string command(const std::string & com);

	~Connection();
};

#endif /* CONNECTION_H_ */
