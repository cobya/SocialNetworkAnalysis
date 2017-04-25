//------------------------------------------------------------------------------------------------
//
// File: Execute.h
// Author: Coby Allred
// Date: 12/1/16
//
// Description: Defines the execute class and its function prototypes
//
//------------------------------------------------------------------------------------------------

#ifndef EXECUTE_H
#define EXECUTE_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "Graph.h"

using namespace std;

class Output {
private:
	char* outputFileName; // Name of the output file
	ofstream outputFile; // Output file stream
	Graph* outputGraph; // The graph created from the input
	string rootUser; // The root user's username
	vector<Node*> outputNodes; // Nodes to be outputted

	void setInDegCent(); // Traverses the graph and its vector of users and increments the indegcent for each followed user 

public:
	Output();
	Output(char* outputFileName, string rootUser, Graph* outputGraph);

	void doWork(); // Executes the main program functions
	bool printOutput(); // Prints the output 

};

#endif

//------------------------------------------------------------------------------------------------