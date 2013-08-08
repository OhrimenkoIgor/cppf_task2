#ifndef MODULEEXCEPTIONS_H_
#define MODULEEXCEPTIONS_H_

#include <stdexcept>

class InvalidArgumentException: public std::invalid_argument {
public:
	explicit InvalidArgumentException(const std::string & arg) :
			invalid_argument(arg) {
	}
};

#endif /* MODULEEXCEPTIONS_H_ */
