
#ifndef CONNECTION_H_
#define CONNECTION_H_

#include <string>

class Connection {
public:
	Connection();

	std::string command(std::string com);

	~Connection();
};

#endif /* CONNECTION_H_ */
