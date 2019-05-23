#include "AlgorithmSortQuick.h"

AlgorithmSortQuick::AlgorithmSortQuick(int k) : SelectionAlgorithm(k) 
{
}

int AlgorithmSortQuick::select() {

	int right;

	cin >> right;
	int *dataSet = new int[right];
	
	for (int i = 0; i < right; i++) {
		cin >> dataSet[i];
	}

	return quickselect(dataSet, 0, right - 1, k);
}

int AlgorithmSortQuick::quickselect(int *dataSet, int left, int right, int k) {

	this->quickSort(dataSet, left, right);

	return dataSet[k - 1];
}

int AlgorithmSortQuick::findPivot(int *dataSet, int left, int right) {
	
	int Center = (left + right) / 2;

	if (dataSet[Center] > dataSet[left])
		swap(dataSet[left], dataSet[Center]);
	if (dataSet[right] > dataSet[left])
		swap(dataSet[left], dataSet[right]);
	if (dataSet[right] > dataSet[Center])
		swap(dataSet[Center], dataSet[right]);

	swap(dataSet[Center], dataSet[right - 1]);

	return dataSet[right - 1];
}

void AlgorithmSortQuick::quickSort(int *dataSet, int left, int right) {

	if (left + 10 <= right) {

		int pivot = this->findPivot(dataSet, left, right);
		int i = left;
		int j = right - 1;

		for (;;) {

			while (dataSet[++i] > pivot){}
			while (pivot > dataSet[--j]){}

			if (i < j)
				swap(dataSet[i], dataSet[j]);
			else
				break;
		}

		swap(dataSet[i], dataSet[right - 1]);

		this->quickSort(dataSet, left, i - 1);
		this->quickSort(dataSet, i + 1, right);
	}
	else
		this->insertionSort(dataSet, left, right);

}

void AlgorithmSortQuick::insertionSort(int *dataSet, int left, int right) {

	for (int i = left; i < right + 1; i++) {
		int number = dataSet[i];
		int index  = i;

		for (int j = i + 1; j < right + 1; j++) {
			int current = dataSet[j];

			if (current > number) {
				number = current;
				index  = j;
			}
		}

		if (index != i) {
			int temp       = dataSet[i];
			dataSet[i]     = number;
			dataSet[index] = temp;
		}
	}
}
