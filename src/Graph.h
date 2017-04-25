//------------------------------------------------------------------------------------------------
//
// File: graph.h
// Author: Coby Allred
// Date: 12/1/16
//
// Description: Defines the graph class and its function prototypes
//
//------------------------------------------------------------------------------------------------

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "Node.h"

using namespace std;

class Graph {
private:
	vector<Node*> twitUsers; // Vector of all nodes in the graph
	bool valid; // Whether or not the graph is valid

public:
	Graph(); // Default constructor

	void setValid(bool isValid); // Sets whether graph is valid or not
	
	Node* returnRootUser(string username); // Returns the root user given a username
	vector<Node*>& returnTwitUsers(); // Returns a reference to the users vector
	bool returnValid(); // returns whether or not graph is valid

};

#endif

//------------------------------------------------------------------------------------------------


