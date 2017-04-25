//------------------------------------------------------------------------------------------------
//
// File: edge.h
// Author: Coby Allred
// Date: 12/1/16
//
// Description: Defines the graph's Edge class and its function prototypes
//
//------------------------------------------------------------------------------------------------

#ifndef EDGE_H
#define EDGE_H

#include <vector>
#include <string>

using namespace std;

//------------------------------------------------------------------------------------------------

class Node; // Forward declaration for the Node class

class Edge {
private:
	Node* adjNode; // Adjacent Node*, following user

public:
	Edge(); // Default constructor
	Edge(Node* adjNode); // Constructor given the node

	Node* returnNode() const { // Returns the adjNode pointer
		return this->adjNode;
	}
};

#endif

//------------------------------------------------------------------------------------------------


