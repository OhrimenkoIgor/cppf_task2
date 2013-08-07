#include "AppServer.h"

std::string AppServer::invoke(std::string module_command) {
	using std::string;
	string ret;

	//TODO
	try {
		std::string module_name, command;
		size_t dc_pos = module_command.find("::");

		if (dc_pos != string::npos) {
			module_name = module_command.substr(0, dc_pos);
			command = module_command.substr(dc_pos + 2, string::npos);
		} else {
			command = module_command;
		}

		if(module_name != ""){
			ret = modules.at(module_name)->invoke(command);
		}

	} catch (const std::out_of_range& oor) {

	}

	return ret;
}

AppServer::AppServer(){

}
