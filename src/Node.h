//------------------------------------------------------------------------------------------------
//
// File: node.h
// Author: Coby Allred
// Date: 12/1/16
//
// Description: Contains the graph's Node class and its function prototypes
//
//------------------------------------------------------------------------------------------------

#ifndef NODE_H
#define NODE_H

#include <algorithm>
#include <vector>
#include <string>
#include "Edge.h"

using namespace std;

class Node {
private:
	string username;  // Label for node, twitter username
	vector<Edge*> followers;    // List of node's followers, stored as vector of Node pointers
	vector<Edge*> following; // List of nodes this user is following
	int inDegCent; // Inner degree of centrality
	bool included; // Whether or not it is within 3

public:
	Node(); // Default Constructor
	Node(string username); // Constructs with just a username
	Node(Edge* follower, string username); // Constructs with a follower and username
	
	void addFollower(Edge* newFollower); // Adds a Node* to the followers vector
	void addFollowing(Edge* newFollowing); // Adds a Node* to the following vector
	void setInDegCent(int degree); // Sets the inner degree of centrality
	void setIncluded(bool include); // Sets included
	vector<Edge*>& returnFollowers(); // Returns the followers vector
	vector<Edge*>& returnFollowing(); // Returns the following vector
	string returnUsername() const; // returns the username
	int returnInDegCent() const; // returns the inner degree of centrality
	bool returnIncluded(); // returns included
};

#endif

//------------------------------------------------------------------------------------------------


