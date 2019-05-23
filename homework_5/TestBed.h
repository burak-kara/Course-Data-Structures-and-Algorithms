#include <iostream>
#include <ctime>
#include "SelectionAlgorithm.h"
#include "AlgorithmSortK.h"
#include "AlgorithmSortAll.h"
#include "AlgorithmSortHeap.h"
#include "AlgorithmSortQuick.h"

using namespace std;

class TestBed
{
private:
	SelectionAlgorithm *algorithm;
public:
	TestBed();
	~TestBed();
	void setAlgorithm(int, int);
	void execute();

};


