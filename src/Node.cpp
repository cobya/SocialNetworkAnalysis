//------------------------------------------------------------------------------------------------
//
// File: node.cpp
// Author: Coby Allred
// Date: 12/1/16
//
// Description: Defines the Node class's functions
//
//------------------------------------------------------------------------------------------------

#include "Node.h"

// Default Node constructor
Node::Node() {
	this->inDegCent = 0;
	this->username = "NULL";
	this->included = false;
	return;
}

// Node constructor given username
Node::Node(string username) {
	this->username = username;
	this->inDegCent = 0;
	this->included = false;
	return;
}

// Node constructor given follower edge + username
Node::Node(Edge* follower, string username) {
	this->username = username;
	this->inDegCent = 0;
	this->followers.push_back(follower);
	this->included = false;
	return;
}

// Adds an Edge to the vector of followers
void Node::addFollower(Edge* newFollower) {
	this->followers.push_back(newFollower);
	return;
}

// Sets the inner degree of centrality
void Node::setInDegCent(int degree) {
	this->inDegCent = degree;
	return;
}

// Returns the vector of followeres
vector<Edge*>& Node::returnFollowers() {
	return this->followers;
}

// Returns the Node's username
string Node::returnUsername() const {
	return this->username;
}

// Returns the node's inner degree of centrality
int Node::returnInDegCent() const {
	return this->inDegCent;
}

// Sets whether the Node has been included in the output nodes
void Node::setIncluded(bool include){
	this->included = include;
	return;
}

// Returns whether or not the Node is included
bool Node::returnIncluded() {
	return this->included;
}

// Adds a following Edge
void Node::addFollowing(Edge* newFollowing) {
	this->following.push_back(newFollowing);
	return;
}

// Returns the vector of users the Node is following
vector<Edge*>& Node::returnFollowing() {
	return this->following;
}
