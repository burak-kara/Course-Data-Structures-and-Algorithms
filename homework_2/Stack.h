#ifndef _STACK_
#define _STACK_

#include <iostream>
#include "StackItem.h"

using namespace std;

class Stack {

public:
	Stack();
	~Stack();
	void push(StackItem*);
	StackItem* pop();
	StackItem* top();
	bool isEmpty();

private:
	StackItem *head;

};

#endif 