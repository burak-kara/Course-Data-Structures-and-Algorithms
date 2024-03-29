//============================================================================
// Name        : BinaryHeap.cpp
// Author      : Hasan Sozer
// Version     : 1.2
// Copyright   : (c) 2013 Ozyegin University
// Description : Includes the (incomplete) implementation file of the  
//               BinaryHeap class that will be used as part of the program    
//               to be submitted as Homework 4, which is assigned in the   
//				 context of the course CS201, Data Structures and Algorithms.
//               
//				 THE IMPLEMENTATION MUST BE COMPLETED TO MAKE ALL THE TESTS
//				 IN THE MAIN METHOD PASS.
//
//				 After completing the heap implementation, "BinaryHeap.h" and
//				 "BinaryHeap.cpp" files will be used for extending homework 1,
//				 and the extended program will be submitted as Homework 4.
//============================================================================

#include "BinaryHeap.h"

BinaryHeap::BinaryHeap(int capacity) {
	this->capacity = capacity;

	// The element at index 0 is not used!
	// The root element will be placed at index 1
	heap = new int[capacity + 1];
	size = 0;
	heap[0] = 0;
}

BinaryHeap::~BinaryHeap() {
	delete[] heap;
}

void BinaryHeap::insert(int element) {

	// TO BE COMPLETED

	// The capacity of the heap is assumed to be fixed.
	// Insert the element if size < capacity
	// Do nothing otherwise.

	if (this->size >= this->capacity)
		return;

	size++;
	int hole = size;
	heap[hole] = element;
	percolateUp(hole);

	// After the new element is inserted, perform a percolate up operation here.
	// You can add a percolateUp method to the class,
	// or just implement the operations within this insert method.
}

void BinaryHeap::deleteMin() {

	// TO BE COMPLETED

	// If the size is less than 1, do nothing and stop
	// Otherwise, replace the root of the heap with the last element on the last level
	// Then, call the percolateDown function by providing the index of the root node, i.e., 1

	if (size < 1) {
		return;
	}
	else {

		heap[1] = heap[size];
		heap[size] = NULL;
		size--;
		percolateDown(1);

	}

}

int BinaryHeap::getMin() {

	// TO BE COMPLETED

	// If the size is less than 1, return -1
	// Otherwise, return the value of the root node

	return (size < 1) ? -1 : heap[1];

}

void BinaryHeap::percolateUp(int hole) {

	if (hole > 1 && parent(hole) > 0 && heap[parent(hole)] > heap[hole]) {

		swap(hole, parent(hole));
		percolateUp(parent(hole));
	}

}

void BinaryHeap::percolateDown(int hole) {

	// TO BE COMPLETED

	// Compare the node with its children; if they are in the correct order, stop
	// Otherwise, swap the element with the smallest child
	// Repeat the operation for the swapped child node

	int leftChild  = 2 * hole;
	int rightChild = 2 * hole + 1;

	// parent(hole) * 2

	if (leftChild <= this->size && rightChild <= this->size && heap[leftChild] <= heap[rightChild]) {

		if(heap[leftChild] < heap[hole]) {
			swap(hole, leftChild);
			percolateDown(leftChild);
		}
	}
	else if (leftChild <= this->size && rightChild <= this->size && heap[rightChild] <= heap[leftChild] ) {

		if (heap[rightChild] < heap[hole]) {
			swap(hole, rightChild);
			percolateDown(rightChild);
		}

	}
	else if (leftChild <= this->size && rightChild > this->size && heap[leftChild] < heap[hole]) {

		swap(hole, leftChild);
		percolateDown(rightChild);

	}
}

void BinaryHeap::swap(int i, int j) {
	int t = heap[i];
	heap[i] = heap[j];
	heap[j] = t;
}

int BinaryHeap::parent(int i) {

	if (i > 1)
		return (i / 2);
	return -1;
}
