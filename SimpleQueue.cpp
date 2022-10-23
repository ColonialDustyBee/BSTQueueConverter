#include <iostream>
#include "SimpleQueue.h"
#include "BinarySearchTree.h"
BSTQueueConverter::BSTQueueConverter() {};

void BSTQueueConverter::Enqueue(int item) {
//Enqueue: Add an item to the end of the queue 
	queue[end] = item;
	end++;
}

int BSTQueueConverter::Dequeue() {
//Dequeue: Removes the item at the front of the queue and returns it
// Will require us to shift an item first and then decreasing said item.
	int item = queue[front]; // save item
	for (int i = 0; i < end - 1; i++) { // code comes from code from unsorted list, got an idea to implement same thing here
		queue[i] = queue[i + 1]; // shift elements
	}
	end--; // decrease the end.
	return item;
}