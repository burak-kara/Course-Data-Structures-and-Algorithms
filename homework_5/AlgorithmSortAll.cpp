#include "AlgorithmSortAll.h"

AlgorithmSortAll::AlgorithmSortAll(int k): SelectionAlgorithm(k)
{
	
}

int AlgorithmSortAll::select() {

	int n   = 0;
	int key = 0;

	// get the how many numbers we'll have from data set
	cin >> n;
	pNums = new int[n];

	// initialize the all elements of array called pNums with length n
	for (int i = 0; i < n; i++) { 

		pNums[i] = 0;

	}

	// get all number from data set and store all of them in array called pNums
	for (int i = 0; i < n; i++) { 

		cin >> pNums[i];

	}

	// sort the array in decreasing order
	for (int i = 1; i < n; i++) { 

		for (int j = i; j > 0 && pNums[j] > pNums[j - 1]; j--) {

			key			 = pNums[j];
			pNums[j]	 = pNums[j - 1];
			pNums[j - 1] = key;

		}

	}

	//return kth largest element 
	return pNums[k - 1];

}

/*

when got the same number second time or much more time
that s not the kth largest. that s just the kth number in sorted array

*/