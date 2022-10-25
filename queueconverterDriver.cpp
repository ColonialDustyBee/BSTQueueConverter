#include <iostream>
#include <fstream>
#include <string>
#include "BinarySearchTree.h"
using namespace std;

int main() {
	ifstream inFile;
	ofstream outFile;
	string lineOfFile; // meant to get length of file.
	string command; // meant to keep track of commands
	int length = 0; // length counts lines of file
	inFile.open("Input.txt");
	while (!inFile.eof()) {
		getline(inFile, lineOfFile); // Counts line
		length++;
	}
	// meant to add items into BST
	BinarySearchTree BST(length); // initializes queue
	inFile.close();
	inFile.open("Input.txt");
	while (!inFile.eof()) {
		inFile >> command;
		if (command == "PutItem") {
			inFile >> command;
			int convert = stoi(command);
			BST.putItem(convert);
		}
	}
	inFile.close();
	outFile.open("OutPut.txt");
	BST.Enqueue(); // adds all items into a queue.
	for (int i = 0; i < length - 1; i++) {
		outFile << BST.Dequeue() << endl; // Dequeues in hopefully ascending order.
	}
	outFile.close();
	cout << "Test Driver Successfully Finished!" << endl;
	return 0;
}
