//------------------------------------------------------------------------------------------------
//
// File: input.h
// Author: Coby Allred
// Date: 12/1/16
//
// Description: Defines the input class and its function prototpyes
//
//------------------------------------------------------------------------------------------------

#ifndef INPUT_H
#define INPUT_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Graph.h"

using namespace std;

class Input {
private:
	char* inputFileName; // Input filename
	ifstream inputFile; // Input filestream
	Graph inputGraph; // Input graph 

	void addInputLine(string username, string follower); // Searches for username to find its User class, if any, and adds it to to the vector of edges

public:
	Input(); // Default constructor
	Input(char* inputFileName); // Creates Input given a filename

	bool getInput(); // Reads the inputs and creates the graph, returns true if successful, false if not

	bool isUsernameValid(string username); // Checks for valid username

	Graph& returnGraph() { // Returns a reference to the graph
		return inputGraph;
	}
};

#endif