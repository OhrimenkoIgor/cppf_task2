
#include <stdexcept>
#include <memory>

#include "Module.h"

std::string Module::invoke(std::string command){
	using std::string;
	string ret;
	try{
		std::string command_name, arguments;
		size_t space_pos = command.find(" ");
		command_name = command.substr(0, space_pos);
		arguments = command.substr(space_pos + 1, string::npos);

		std::shared_ptr<Command> com = commands.at(command_name)->clone();
		ret = com->invoke(arguments);
	} catch (const std::out_of_range& oor){
		//TODO return string "no command"
	}
	return ret;
}

