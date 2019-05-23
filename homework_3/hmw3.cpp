#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main() {

	BinarySearchTree *tree = new BinarySearchTree();

	int input = 0;

	cout << "Enter a set of numbers (-1 to stop) :";
	cin >> input;

	while (input != -1) {

		tree->insert(input);
		cin >> input;
	}

	tree->printPreorder();
	tree->printInorder();
	tree->printPostOrder();
	
	delete tree;

}