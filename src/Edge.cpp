//------------------------------------------------------------------------------------------------
//
// File: edge.cpp
// Author: Coby Allred
// Date: 12/1/16
//
// Description: Implements the Edge constructors
//
//------------------------------------------------------------------------------------------------

#include "Edge.h"

// Default constructor, does nothing
Edge::Edge() {
	return;
}

// Edge constructor given a specified Node* 
Edge::Edge(Node* adjUser) {
	this->adjNode = adjUser;
	return;
}