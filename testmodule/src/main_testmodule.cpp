#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <iostream>

#include "TestModule.h"
#include "TestModuleCommands.h"

int main(void) {

	TestModule tm;

/*	std::string ans1 = tm.invoke("getstate");
	std::string ans2 = tm.invoke("getstat");
	std::string ans3 = tm.invoke("getparams");

	std::string ans4 = tm.invoke("setparams name=newname interval=2");
	std::string ans5 = tm.invoke("setparams newname2 interval=3");
	std::string ans6 = tm.invoke("setparams newname3 5");
	std::string ans7 = tm.invoke("setparams newname4");
	std::string ans8 = tm.invoke("setparams");
*/


	std::string mes;

	while (true) {
		//getline(std::cin, mes);

		std::string mes = tm.receive_message();
		std::string ans = tm.invoke(mes);
		tm.send_message(ans);
		if (mes == "exit") {
			break;
		}
	}

	return EXIT_SUCCESS;
}
