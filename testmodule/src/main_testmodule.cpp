
#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <iostream>

#include "TestModule.h"

int main(void) {

	TestModule tm;

	std::string line;

	while(true){
		getline(std::cin, line);
		if(line == "exit"){
			break;
		}
	}

	return EXIT_SUCCESS;
}
