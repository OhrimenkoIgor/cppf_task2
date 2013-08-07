
#ifndef CONNECTION_H_
#define CONNECTION_H_

#include <string>

class Connection {
	int sockfd;
public:
	Connection(int sockfd_v);

	std::string read_string();
	void write_string(std::string);

	~Connection();
};

#endif /* CONNECTION_H_ */
