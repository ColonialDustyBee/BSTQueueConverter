#pragma once
/*
Enqueue: Add an item to the end of the queue
Dequeue: Removes the item at the front of the queue and returns it
In this case we're only going to need these two operations from a queue.
*/
class BSTQueueConverter{
private:
	int front = 0; // Start the queue.
	int length = 0;
	int end = 0; // end of the queue
	int* queue = new int[length]; // Make a dynamic array
public:
	BSTQueueConverter();
	void Enqueue(int item); 
	int Dequeue();
};