#include "AlgorithmSortHeap.h"

AlgorithmSortHeap::AlgorithmSortHeap(int k) :SelectionAlgorithm(k)
{
}

int AlgorithmSortHeap::select() {
	
	int n;
	int number;

	heap = new BinaryHeap(k);
	cin >> n;

	for (int i = 0; i < k; i++) {
		
		cin >> number;
		heap->insert(number);
	}

	for (int i = k; i < n; i++) {

		cin >> number;
		if (heap->getMin() < number) { 

			heap->deleteMin();
			heap->insert(number);
		}

	}

	return heap->getMin();
}