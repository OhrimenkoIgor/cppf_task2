#include "Command.h"
#include "ModuleExceptions.h"

using namespace std;

//TODO fix. now fixed order (if skipped, paramname must be specified)
void Command::parse_arguments(const std::string & arguments) {
	//vector<string> vector_arguments(this->params.size());
	string arument_value, argument, value;

	size_t start_search_pos = 0;
	size_t first_space_pos = 0;
	size_t equal_pos = 0;
	for (size_t i = 0; i < this->params.size(); i++) {
		//get argument and value
		if(start_search_pos == string::npos){
			break;
		}
		first_space_pos = arguments.find_first_of(" \t", start_search_pos);
		arument_value = arguments.substr(start_search_pos, first_space_pos - start_search_pos);
		start_search_pos = arguments.find_first_not_of(" \t", first_space_pos);

		equal_pos = arument_value.find('=');
		if (equal_pos != string::npos) { //= sign present
			argument = arument_value.substr(0, equal_pos);
			value = arument_value.substr(equal_pos + 1);
			while (i < this->params.size() && argument != params[i].paramName) {
				i++;
			}
			if (argument != params[i].paramName) {
				throw InvalidArgumentException(name + " invalid argument " + argument);
			}
		} else { //= sign absent
			value = arument_value;
		}
		if (value == ""){
			continue;
		}
		if (params[i].type == Params::Type::STR) {
			params[i].str_val = value;
		} else if (params[i].type == Params::Type::INT) {
			//if(! (istringstream (value) >> params[i].int_val)){
			//	throw InvalidArgumentException(name + " " + params[i].paramName + " must be integer");
			//}
			size_t idx = 0;
			try {
				params[i].int_val = stoi(value, &idx);
				if (idx != value.size()) {
					throw invalid_argument("");
				}
			} catch (invalid_argument &) {
				throw InvalidArgumentException(name + " " + params[i].paramName + " must be integer");
			}
		}
	}
}

