#include "BinarySearchTree.h"
#include <iostream>

using namespace std;
BinarySearchTree::BinarySearchTree() { };

int BinarySearchTree::GetLength() {
	return CountNodes(tree); // this might end up causing an issue
}
int BinarySearchTree::CountNodes(Node*& tree) {
	if (tree == nullptr) { // If there isn't a tree
		return 0;
	}
	else {
		return CountNodes(tree->left) + CountNodes(tree->right) + 1;
	} // simply returns values of left subtree and right subtree which also includes the offset of + 1.
}
/*
	Three cases to worry about
	if the tree is empty, make a new root node.
	if the tree isn't empty and the item we wish to insert is less than the root node, it should insert on the left subtree
	if the tree isn't empty and the item we wish to insert is greater than the root node, it should insert on the right subtree
*/
void BinarySearchTree::putItem(int value) {
	insert(tree, value); // calls recursive
}
void BinarySearchTree::insert(Node*& tree, int value) {
	if (tree == nullptr) { // if tree is empty
		tree = new Node;
		// left and right nodes point to nothing
		tree->left = nullptr; 
		tree->right = nullptr;
		tree->info = value; // insert value respectively.
	}
	else if (value < tree->info) {
		insert(tree->left, value); // Insert on left subtree
	}
	else {
		insert(tree->right, value); // Insert on right subtree.
	}
}
/* Three cases - these will be called in retrieve private member function.
- if item is less than the item on the left then we search left
- if item is greater than the item on the right then we search right subtree
- we keep going until the item is found.
- if it isn't found then we return that it wasn't found.
 */
int BinarySearchTree::getItem(int value) {
	value = retrieve(tree, value);
	return value;
}
int BinarySearchTree::retrieve(Node*& tree, int value) {
	if (tree == nullptr) {
		return -1; // This will indicate the value isn't present within the tree since we're assuming this can ONLY hold value of positive.
	}
	else if (value < tree->info) {
		retrieve(tree->left, value); // Search left subtree
	}
	else if (value > tree->info) {
		retrieve(tree->right, value); // Search right subtree
	}
	else {
		value = tree->info; // value has been indeed found.
		return value; // Will return value to getItem.
	}
}
/*
Three cases to worry
- Case 1 No child in node (makes this a leaf node) - cut link of its parent node and delete the current node.
 17
   \
   19 - Deleting 19 just requires us to sever link with 17 and then delete 19

- Case 2 One child node - link parent to child node being deleted since BST properties MUST be conserved
	 12
	/  \
   5    15
  / \
 3   7  <- deleting 7, requires us to link child node (in this case 9) with the parent node of the node being deleted (in this case linking 5 with 9.)
	  \
	   9

- Case 3 Two children nodes - requires us to fill with min node of the right most subtree OR max node of the leftmost subtree (either one works here).
in order it's: find min value in the right most subtree
copy the min value to the value that is being deleted
delete the duplicate from the right subtree
     12
	/  \
   5   15  (deleting 5 from here requires us to find the min value in the right subtree, in this case it's 4, replace 5 with value 4, and then delete 4).
  / \
 3   7  
	/ \
   4   9
in this case afterwards we'd be left with this subtree
	 12
	/  \
   4   15  <- replaced 5 with 4.
  / \
 3   7
	  \
       9
*/
void BinarySearchTree::deleteItem(int value) {
	Delete(tree, value);
}
int BinarySearchTree::findMin(Node*& tree) {
	int value = 0;
	while (tree->right != nullptr) {
		tree = tree->right;
		value = tree->info; // rewrite value
	}
	return value;
}
// We first need to find if the item is in the list at all. 
void BinarySearchTree::Delete(Node*& tree, int value) {
	if (tree == nullptr) {
		return; // if the tree is empty then it should simply return
	}
	else if (value < tree->info) {
		Delete(tree->left, value); // look in left subtree for value
	}
	else if (value > tree->info) {
		Delete(tree->right, value); // look in right subtree for value
	}
	else { // value is found
		DeleteNodeFound(tree, value);
	}
}
void BinarySearchTree::DeleteNodeFound(Node*& tree, int value) {
	// Case 1 - if node is a leaf node.
	if (tree->left == nullptr  && tree -> right == nullptr) {
		delete tree; // delete the tree node.
	}
	// Case 2 - one child node in the node we wish to delete
	else if (tree->left == nullptr) {
		Node* temp = tree; // make temp ptr.
		tree = tree->right;
		delete temp;
	}
	else if (tree->right == nullptr) {
		Node* temp = tree;
		tree = tree->left; // assign value to left most.
		delete temp;
	}
	// Case 3  - two children nodes connected to node we wish to delete --MUST FIX--
	else {
		int value = 0;
		Node* temp = tree; // Makes new temp.
		temp->info = findMin(tree->right); // find min in rightmost
		value = temp->info; // rewrite value
		Delete(tree->right, value); // Call delete to delete value.
	}
	
	
}
void BinarySearchTree::printTree(){ // meant to be for the user to call.
	printTree(tree);
}
// we should also make a member function that prints the entire tree
void BinarySearchTree::printTree(Node*& tree) {
	if (tree == nullptr) {
		return;
	}
	else {
		cout << tree->info << endl;
		printTree(tree->left);
		printTree(tree->right);	
	}
}