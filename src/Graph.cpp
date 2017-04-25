//------------------------------------------------------------------------------------------------
//
// File: graph.h
// Author: Coby Allred
// Date: 12/1/16
//
// Description: Defines the graph class' functions
//
//------------------------------------------------------------------------------------------------

#include "Graph.h"

// Default graph constructor
Graph::Graph() {
	this->valid = true;
	return;
}

// Sets whether graph is valid or not
void Graph::setValid(bool isValid) {
	this->valid = isValid;
}

// Searches the graph to return a Node* to the root user
Node* Graph::returnRootUser(string username) {
	if (this->valid == false) { // If graph not valid, exit
		return NULL;
	}
	
	int location = -1;
	for (int i = 0; (unsigned)i < this->twitUsers.size(); i++) { // Increment through graph and search
		if (username.compare(this->twitUsers.at(i)->returnUsername()) == 0) {
			location = i;
			break;
		}
	}

	if (location != -1) { // If found, return location
		return this->twitUsers.at(location);
	}
	else { // Else return NULL
		return NULL;
	}
}

// Returns the vector of twitUsers
vector<Node*>& Graph::returnTwitUsers() {
	return this->twitUsers;
}

// Returns whether graph is valid or not
bool Graph::returnValid() {
	return this->valid;
}
