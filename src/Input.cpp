//------------------------------------------------------------------------------------------------
//
// File: input.cpp
// Author: Coby Allred
// Date: 12/1/16
//
// Description: Defines the functions used in program input
//
//------------------------------------------------------------------------------------------------

#include "Input.h"
#include "Node.h"

// Adds the input line to the graph
void Input::addInputLine(string username, string follower) {
	int userLoc = -1;
	int followLoc = -1;

	for (int i = 0; (unsigned)i < this->inputGraph.returnTwitUsers().size(); i++) { // Check graph for matching usernames
		if (username.compare(this->inputGraph.returnTwitUsers().at(i)->returnUsername()) == 0) {
			userLoc = i;
		}
		if (follower.compare(this->inputGraph.returnTwitUsers().at(i)->returnUsername()) == 0) {
			followLoc = i;
		}
	}

	if (userLoc == -1 && followLoc == -1) { // If both follower and user aren't found
		Node* newFollower = new Node(follower); // Creates a node for the follower
		Edge* newFollowerEdge = new Edge(newFollower); // Creates an edge for the follower
		Node* newUser = new Node(newFollowerEdge, username); // Creates the new user
		Edge* newFollowing = new Edge(newUser); // Creates an following edge for the user

		newFollower->addFollowing(newFollowing); // Adds the following edge to the follower node

		this->inputGraph.returnTwitUsers().push_back(newFollower); // Pushes the new follower
		this->inputGraph.returnTwitUsers().push_back(newUser); // Pushes the new user
	}
	else if (userLoc == -1 && followLoc != -1) { // If user node isn't found
		Edge* newFollower = new Edge(this->inputGraph.returnTwitUsers().at(followLoc)); // Adds follower edge
		Node* newUser = new Node(newFollower, username); // Creates the user node with the follower edge and username
		Edge* newFollowing = new Edge(newUser); // Creates the following edge from the new user

		this->inputGraph.returnTwitUsers().at(followLoc)->addFollowing(newFollowing); // Adds following edge to the follower node

		this->inputGraph.returnTwitUsers().push_back(newUser); // Pushes new user
	}
	else if (userLoc != -1 && followLoc == -1) { // If the follower node isn't found
		Node* newFollow = new Node(follower); // Creates the follower node
		Edge* newEdge = new Edge(newFollow); // Creates the follower edge
		Edge* newFollowing = new Edge(this->inputGraph.returnTwitUsers().at(userLoc)); // Creates the following edge
		newFollow->addFollowing(newFollowing); // Adds the following edge to the new follower
		
		this->inputGraph.returnTwitUsers().push_back(newFollow); // Pushes follower node
		this->inputGraph.returnTwitUsers().at(userLoc)->addFollower(newEdge); // Adds follower edge to the user node

	}
	else if (userLoc != -1 && followLoc != -1) { // If both nodes are found
		Edge* newEdge = new Edge(this->inputGraph.returnTwitUsers().at(followLoc)); // Creates the follower edge
		this->inputGraph.returnTwitUsers().at(userLoc)->addFollower(newEdge); // Adds follower edge

		Edge* newFollowing = new Edge(this->inputGraph.returnTwitUsers().at(userLoc)); // Creates following edge
		this->inputGraph.returnTwitUsers().at(followLoc)->addFollowing(newFollowing); // Adds following edge
	}
	
	return;
}

// Default input constructor
Input::Input() {
	this->inputFileName = NULL;
	return;
}

// Constructs Input given a filename
Input::Input(char* inputFileName) {
	this->inputFileName = inputFileName;
	return;
}

// gets the input from the file and adds it to the graph
bool Input::getInput() {
	string inputLine;

	inputFile.open(inputFileName); // Opens the file

	if (inputFile.is_open()) { // If open, get lines
		while (getline(inputFile, inputLine)) {
			string user, follower, shouldBeNothing; // Temp strings

			istringstream inputParsing(inputLine); // Parsing the input
			inputParsing >> user;
			inputParsing >> follower;
			inputParsing >> shouldBeNothing;

			if (isUsernameValid(user) == true && isUsernameValid(follower) == true && shouldBeNothing.empty() == true) { // If usernames are valid, continue
				for (int i = 0; (unsigned)i < user.size(); i++) { // Remove and return / newline chars
					if (user.at(i) == '\r' || user.at(i) == '\n') {
						user.erase(user.at(i));
					}
				}
				for (int i = 0; (unsigned)i < follower.size(); i++) { // Remove and return / newline chars
					if (follower.at(i) == '\r' || follower.at(i) == '\n') {
						user.erase(follower.at(i));
					}
				}

				addInputLine(user, follower); // Adds the user using the above function
			}
			else {
				this->inputGraph.setValid(false);
				return true; // Returns true since it must create empty output
			}
		}
	}
	else {
		return false; // False to exit program
	}

	return true;
}

// Checks for username validity
bool Input::isUsernameValid(string username) {
	int isvalid = 1;

	if (username.length() > 15) { // If length > 15, not valid
		isvalid = 0;
	}
	else { // Else search for non alphanumberics
		for (int i = 0; (unsigned)i < username.length(); i++) {
			if (isalnum(username.at(i)) == false && username.at(i) != '_') {
				isvalid = 0;
				break;
			}
		}
	}

	if (isvalid == 1) {
		return true; // If valid return true
	}
	else { // Else false
		return false;
	}
}

