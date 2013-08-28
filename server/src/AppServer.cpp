#include <unistd.h>

#include "AppServer.h"

AppServer::AppServer() {

}

std::string AppServer::invoke(const std::string & module_command) {
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

		if (module_name != "") {
			ret = modules.at(module_name)->invoke(command);
		}

	} catch (const std::out_of_range& oor) {

	}

	return ret;
}

void AppServer::add_module(const std::string & name, const std::string & path) {

	pid_t childPid; /* Used in parent after successful fork()
	 to record PID of child */
	childPid = fork();
	if (childPid == -1) { /* fork() failed */
		/* Handle error */
	} else if (childPid == 0) { /* Child of successful fork() comes here */
		char * cname = new char[name.size() + 1];
		std::size_t length = name.copy(cname, name.size());
		cname[length] = '\0';
		char * argVec[] = { cname, NULL };
		char * envVec[] = { NULL };
		execve(path.c_str(), argVec, envVec);
	} else {/* Parent comes here after successful fork() */
		//TODO fix it for example with pipe.
		sleep(1);
		modules.emplace(name, std::shared_ptr<ModuleInterface>(new ModuleInterface(name, childPid)));
	}
}
