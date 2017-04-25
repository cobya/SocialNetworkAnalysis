//------------------------------------------------------------------------------------------------
//
// File: Execute.h
// Author: Coby Allred
// Date: 12/1/16
//
// Description: Defines the functions used the program's execution and output
//
//------------------------------------------------------------------------------------------------

#include "Execute.h"

// Comparator used in sorting the nodes
bool isLessThan(const Node* leftNode, const Node* rightNode) {
	string lowerLeft = leftNode->returnUsername(); // Creates a new string with left username
	string lowerRight = rightNode->returnUsername(); // Creates a new string with right username
	int leftInDegCent = leftNode->returnInDegCent(); // Left indegcent
	int rightInDegCent = rightNode->returnInDegCent(); // Right indegcent

	transform(lowerLeft.begin(), lowerLeft.end(), lowerLeft.begin(), ::tolower); // Transforms left username to lowercase
	transform(lowerRight.begin(), lowerRight.end(), lowerRight.begin(), ::tolower); // Transforms right username to lowercase

	if (leftInDegCent > rightInDegCent) { // Comparisons to sort with
		return true;
	}
	else if (leftInDegCent == rightInDegCent && lowerLeft.compare(lowerRight) < 0) {
		return true;
	}
	else {
		return false;
	}
}

// Sets the inner degree of centrality for each node
void Output::setInDegCent() {

	for (int i = 0; (unsigned)i < this->outputGraph->returnTwitUsers().size(); i++) { // Increments through all of the users on the graph
		Node* setUser = this->outputGraph->returnTwitUsers().at(i); // Returns the User node
		setUser->setInDegCent(this->outputGraph->returnTwitUsers().at(i)->returnFollowers().size()); // Increments the in degree of centrality for the edge's user
	}
	return;
}

// Default output class constructor
Output::Output() {
	this->outputFileName = NULL;
	this->outputGraph = NULL;
	this->rootUser = "NULL";
	return;
}

// Output class constructor given filename, rootuser and outputgraph
Output::Output(char* outputFileName, string rootUser, Graph* outputGraph) {
	this->rootUser = rootUser;
	this->outputFileName = outputFileName;
	this->outputGraph = outputGraph;
	return;
}

// Executes the main program functions to discover users and set inner degree of centrality
void Output::doWork() {

	if (this->outputGraph->returnValid() == false) { // If something is not valid, exit
		return;
	}
	else {
		setInDegCent(); // Sets the Inner Degree of Centrality for each user

		Node* root = this->outputGraph->returnRootUser(this->rootUser); // rootUser pointer for easy reference

		if (root == NULL) {
			return;
		}

		root->setIncluded(true);

		for (int i = 0; (unsigned)i < root->returnFollowing().size(); i++) { // DISTANCE 1
			root->returnFollowing().at(i)->returnNode()->setIncluded(true); // Sets to included so it won't be double counted
		}

		for (int i = 0; (unsigned)i < root->returnFollowing().size(); i++) { 
			for (int j = 0; (unsigned)j < root->returnFollowing().at(i)->returnNode()->returnFollowing().size(); j++) { // DISTANCE 2
				if (root->returnFollowing().at(i)->returnNode()->returnFollowing().at(j)->returnNode()->returnIncluded() == false) {
					root->returnFollowing().at(i)->returnNode()->returnFollowing().at(j)->returnNode()->setIncluded(true);
					this->outputNodes.push_back(root->returnFollowing().at(i)->returnNode()->returnFollowing().at(j)->returnNode()); // Adds the node to the output list
				}

				for (int k = 0; (unsigned)k < root->returnFollowing().at(i)->returnNode()->returnFollowing().at(j)->returnNode()->returnFollowing().size(); k++) { // DISTANCE 3
					if (root->returnFollowing().at(i)->returnNode()->returnFollowing().at(j)->returnNode()->returnFollowing().at(k)->returnNode()->returnIncluded() == false) {
						root->returnFollowing().at(i)->returnNode()->returnFollowing().at(j)->returnNode()->returnFollowing().at(k)->returnNode()->setIncluded(true);
						this->outputNodes.push_back(root->returnFollowing().at(i)->returnNode()->returnFollowing().at(j)->returnNode()->returnFollowing().at(k)->returnNode()); // Adds the node to the output list
					}
				}
			}
		}

		sort(this->outputNodes.begin(), this->outputNodes.end(), isLessThan); // Sorting the output nodes
	}

	return;
}

// Prints the output of the program
bool Output::printOutput() {

	outputFile.open(outputFileName); // Open the output file

	if (outputFile.is_open()) {

		if (this->outputGraph->returnValid() == false || this->outputGraph->returnRootUser(rootUser) == NULL) { // If something is not valid or root user not found, empty output and exit
			outputFile.close();
			return true;
		}
		else { // Else print output
			outputFile << "Looking for new accounts for " << this->rootUser << " (" << this->outputGraph->returnRootUser(rootUser)->returnInDegCent() << ") to follow" << endl;

			for (int i = 0; (unsigned)i < this->outputNodes.size(); i++) { // Print nodes of users they could be following
				outputFile << this->outputNodes.at(i)->returnUsername() << " (" << this->outputNodes.at(i)->returnInDegCent() << ")" << endl;
			}
		}

		outputFile.close(); // Close output file

	}
	else { // If outputFile is not good, print error
		return false;
	}

	return true;
	
}


