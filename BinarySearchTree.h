#pragma once
class BinarySearchTree
{
	/*
		BST can be defined through the use of a structure
		To clarify, BSTs at the very least should have the following operations available - 
		getLength - simply returns the total number of nodes.
		printTree - in this case it will be enqueue since we're converting this BST into a queue in inorder form, will be accompanied by a dequeue that will return item.
		retrieve - returns items from a particular node - will be subtituted for putItem in this case.
		insert - essentially allows us to initialize the node basically. 
		

	*/
private:
	struct Node { // Define BST
		Node* left;
		Node* right;
		int info;
	}*tree = nullptr;
	
	int length = 0;  // Length of queue
	int front = 0;
	int end = 0;
	int* queue;
	void insert(Node*&, int); // Takes value and inserts it
	int retrieve(Node*&, int); // called by putItem
	void Delete(Node*&, int); // Called by deleteItem
	void DeleteNodeFound(Node*&, int); // Called by Delete
	int findMin(Node*&); // Meant for case 3 in deleting a node.
	void Enqueue(Node*&);
	int CountNodes(Node*&); // Private member function

public:
	BinarySearchTree(); //  Default Constructor
	BinarySearchTree(int); // Parameterized constructor
	~BinarySearchTree();
	int getLength();
	void Enqueue();
	int Dequeue();
	void putItem(int);
	int getItem(int);
	void deleteItem(int);
};
