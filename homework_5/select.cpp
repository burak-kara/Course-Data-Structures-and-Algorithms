#include <iostream>
#include "TestBed.h"

using namespace std;

int main(){

	int type = 0;
	int k    = 0;

	TestBed *testBed = new TestBed;

	cin >> type;
	cin >> k;
	
	testBed->setAlgorithm(type,k);
	testBed->execute();

	delete testBed;

	return 0;
}