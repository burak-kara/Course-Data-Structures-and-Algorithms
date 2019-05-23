#include "AlgorithmSortK.h"

AlgorithmSortK::AlgorithmSortK(int k):SelectionAlgorithm(k)
{

}

int AlgorithmSortK::select() {

	int n = 0;
	int newInput = 0;

	// get the how many numbers we'll have from data set
	cin >> n;
	pNums = new int[k];

	// initialize the all elements of array called pNums with length k
	for (int i = 0; i < k; i++) { 

		pNums[i] = 0;

	}

	// get the numbers from data set and sort them while getting 
	for (int i = 0; i < n; i++) {

		cin >> newInput;

		for (int j = 0; j < k; j++) { 

			if (newInput > pNums[j]) {

				for (int x = k - 1; x > j; x--) {

					pNums[x] = pNums[x - 1];

				}

				pNums[j] = newInput;

				break;
			}

		}

	}

	return pNums[k - 1];

}




