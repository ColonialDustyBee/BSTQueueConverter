#pragma once
class BinarySearchTree
{
	/*
		BST can be defined through the use of a structure
		To clarify, BSTs should have the following methods-
		GetLength - Should simply count the number of nodes, will have member function of CountNodes which will count the nodes recursively.
		getItem - Should insert a Node within the tree with a given value
		deleteItem - Should delete a Node within the tree, should consider 3 cases to solve it recursively.

	*/
private:
	struct Node { // Define a structure
		Node* left;
		Node* right;
		int info;
	}*tree = nullptr;
	
	int length = 0;  // Length of structure.
	void insert(Node*&, int); // Takes value and inserts it
	int retrieve(Node*&, int);
	void Delete(Node*&, int);
	int findMin(Node*&);
	void printTree(Node*&);
	void DeleteNodeFound(Node*&, int);
	int CountNodes(Node*&); // Private member function

public:
	BinarySearchTree(); // Constructor
	int GetLength();
	void printTree();
	void putItem(int);
	int getItem(int);
	void deleteItem(int);
};

