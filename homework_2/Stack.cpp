#include "Stack.h"

Stack::Stack() {

}

Stack::~Stack() {

}

void Stack::push(StackItem* item) {
	
	if (this->isEmpty()) {
		head = item;
	}
	else {

		if (this->top()->n < 0) {

			*this->top() = *item;
		}
		else {

			this->top()->next = item;
		}
	}
}

StackItem* Stack::pop() {

	if (this->isEmpty()) {
	
		return NULL;
	}

	StackItem *setNull = new StackItem("");;
	StackItem *temple	= this->top();
	setNull->isOperator	= false;
	setNull->n			= -1;
	setNull->next		= NULL;
	setNull->op			= -1;
	*this->top() = *setNull;

	return temple;

}

StackItem* Stack::top() {

	if (this->isEmpty()) {
		
		return NULL;
	}

	StackItem *tempHead = head;
	while (tempHead->next != NULL) {

		if (tempHead->next->n >= 0) {

			tempHead = tempHead->next;
		}
		else{

			break;
		}
	}

	return tempHead;

}

bool Stack::isEmpty() {

	if (this->head == NULL) 
		return true;
	if (this->head->n < 0)
		return true;

	return false;

}
