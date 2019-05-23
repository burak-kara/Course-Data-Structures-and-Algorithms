#include <iostream>
#include "SelectionAlgorithm.h"

using namespace std;

class AlgorithmSortQuick : public SelectionAlgorithm {

public:
	AlgorithmSortQuick(int);
	int select();
	int quickselect(int *,int,int,int);
private:
	int findPivot(int*, int, int);
	void quickSort(int *,int, int);
	void insertionSort(int *, int, int);
};