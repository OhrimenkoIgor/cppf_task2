
#ifndef INETSOCKETS_H_
#define INETSOCKETS_H_

#include <memory>
#include <string>


class Connection {
	int sockfd;
	static const int BUF_SIZE = 8192;
public:
	Connection(int sockfd_v);

	Connection(const std::string & serv_hostname = "127.0.0.1", const std::string & serv_port = "12345");

	std::string read_string();
	void write_string(const std::string & s);

	~Connection();
};

class Server {
	int sockfd;
	int portno;
public:
	Server(const std::string & serv_port);
	std::shared_ptr<Connection> accept_connection();
	~Server();
};


#endif /* INETSOCKETS_H_ */
