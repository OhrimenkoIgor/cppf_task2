
#include <iostream>
#include <string>
#include <cstdlib>

#include "Connection.h"

using namespace std;

int main(void) {

	string line;

	Connection con;

	while(true){
		cout << endl << ">";
		getline(cin, line);
		if(line == "exit"){
			break;
		}

		cout << con.command(line);
	}

	return EXIT_SUCCESS;
}
