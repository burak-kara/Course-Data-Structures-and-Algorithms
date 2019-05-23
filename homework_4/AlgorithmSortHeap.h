#include <iostream>
#include "SelectionAlgorithm.h"
#include "BinaryHeap.h"

using namespace std;

class AlgorithmSortHeap : public SelectionAlgorithm
{
public:
	AlgorithmSortHeap(int);
	int select();
private:
	BinaryHeap *heap;
};