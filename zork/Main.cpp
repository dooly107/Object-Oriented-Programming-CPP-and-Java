#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "zork.h"

int main(int argc, char** argv) {
	if (argc != 2) {
		cout << "Error! The arguments are Zork_Executable <filename>" << endl;
		return EXIT_FAILURE;
	}

	string filename = string(argv[1]);
	Zork * zork = new Zork(filename);

	if (zork->startgame == true) {
		zork->start();
	}

	delete zork;

	return 0;
}