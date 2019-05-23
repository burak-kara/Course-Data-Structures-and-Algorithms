#include "AlgorithmSortHeap.h"

AlgorithmSortHeap::AlgorithmSortHeap(int k) :SelectionAlgorithm(k)
{
}

int AlgorithmSortHeap::select() {
	
	int n;
	int num;

	heap = new BinaryHeap(k);
	cin >> n;

	for (int i = 0; i < k; i++) {
		
		cin >> num;
		heap->insert(num);
	}

	for (int i = k; i < n; i++) {

		cin >> num;
		if (heap->getMin() < num) { // change here

			heap->deleteMin();
			heap->insert(num);
		}

	}

	return heap->getMin();
}