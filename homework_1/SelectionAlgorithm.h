#ifndef _SELECTIONALGORITHM_
#define _SELECTIONALGORITHM_

#include <iostream>

using namespace std;

class SelectionAlgorithm 
{
public:
	SelectionAlgorithm();
	SelectionAlgorithm(int);
	virtual int select();
protected:
	int k;
};

#endif