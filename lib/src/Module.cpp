#include <stdexcept>
#include <memory>

#include "Module.h"

std::string Module::invoke(const std::string & command) {
	using std::string;
	std::string command_name, arguments, ret;

	if (command == "help") {
		ret = name + " commands:";
		for (auto it = commands.cbegin(); it != commands.cend(); ++it) {
			ret += " ";
			ret += it->first;
		}
	} else {

		try {
			size_t space_pos = command.find(" ");
			if (space_pos != string::npos) {
				command_name = command.substr(0, space_pos);
				arguments = command.substr(space_pos + 1, string::npos);
			} else {
				command_name = command;
			}
			std::shared_ptr<Command> com = commands.at(command_name)->clone();
			ret = com->invoke(arguments);
		} catch (const std::out_of_range& oor) {
			ret = name + ": no command \"" + command_name +"\"";
		}
	}

	return ret;
}

