#ifndef COMMAND_H_
#define COMMAND_H_

#include <memory>
#include <string>
#include <vector>

class Command {
protected:

	struct Params {
		enum class Type {
			INT, STR
		};
		std::string paramName;
		Type type;
		//union Value{
		int int_val;
		std::string str_val;
		//} value;
	};

	std::string name;
	std::vector<Params> params;

	virtual void parse_arguments(const std::string & arguments);

public:
	Command(const std::string & name_v = "command") :
			name(name_v) {
	}
	std::string get_name() const {return name;}
	virtual std::shared_ptr<Command> clone() const = 0;
	virtual std::string invoke(const std::string & arguments) = 0;
	virtual ~Command() {
	}
	;
};

#endif /* COMMAND_H_ */
