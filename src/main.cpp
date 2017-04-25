//------------------------------------------------------------------------------------------------
//
// File: main.cpp
// Author: Coby Allred
// Date: 12/1/16
//
// Description: Executes the program
//
//------------------------------------------------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "Graph.h"
#include "Input.h"
#include "Execute.h"

//------------------------------------------------------------------------------------------------

using namespace std;

//------------------------------------------------------------------------------------------------

int main(int argc, char *argv[]) {

	if (argc != 4) { // If incorrect # arguments, exit
		printf("Usage: sna inputFile userName outputFile");
		return EXIT_FAILURE;
	}

	Input SNAInput(argv[1]); // Creates the input class

	if (SNAInput.getInput() == true) { // If input file is valid, read input
	}
	else { // Else print error and exit program
		cout << "Error opening " << argv[1] << " for input." << endl;
		return EXIT_FAILURE;
	}

	Output SNAOutput(argv[3], argv[2], &SNAInput.returnGraph()); // Creates the output class

	SNAOutput.doWork(); // Does the work
	if (SNAOutput.printOutput() == true) { // Prints the output
	} 
	else { // If an error in output creation, print error and exit
		cout << "Error creating output file " << argv[3] << "." << endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

//------------------------------------------------------------------------------------------------
