#include <iostream>
#include "SelectionAlgorithm.h"

using namespace std;

class AlgorithmSortAll : public SelectionAlgorithm
{
public:
	AlgorithmSortAll(int);
	int select();
private:
	int *pNums;
};

