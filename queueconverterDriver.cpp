#include <iostream>
#include <fstream>
#include "BinarySearchTree.h"
using namespace std;

int main() {
	BinarySearchTree BST;
	BST.putItem(3); // 3 is the root
	BST.putItem(5);
	BST.putItem(200);
	BST.putItem(2);
	BST.putItem(10);
	BST.putItem(20);
	BST.putItem(2000);
	BST.putItem(40);
	cout << "Length: " << BST.GetLength() << endl;
	BST.printTree();
	cout << "Length: " << BST.GetLength() << endl;
	return 0;
}