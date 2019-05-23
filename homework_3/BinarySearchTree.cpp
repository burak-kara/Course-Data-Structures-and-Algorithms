#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {

	this->root = NULL;

}

BinarySearchTree::~BinarySearchTree() {

	this->deleteNodes(root);

}

void BinarySearchTree::insert(int number) {

	this->insert(number, root);

}

void BinarySearchTree::printPreorder() {

	traversePreorder(root);
	cout << "\n";

}

void BinarySearchTree::printInorder() {

	traverseInorder(root);
	cout << "\n";

}

void BinarySearchTree::printPostOrder() {

	traversePostorder(root);
	cout << "\n";

}

void BinarySearchTree::insert(int number, BinaryTreeNode * & n) {

	if (n == NULL) {

		root = new BinaryTreeNode(number);

	}
	else {

		if (number < n->element) {

			if (n->left != NULL)

				this->insert(number, n->left);

			else {

				n->left = new BinaryTreeNode(number);
			}

		}
		else if (number > n->element) {

			if (n->right != NULL)

				this->insert(number, n->right);

			else {

				n->right = new BinaryTreeNode(number);

			}

		}

	}

}

void BinarySearchTree::deleteNodes(BinaryTreeNode * & n) {

	if (n != NULL) {

		deleteNodes(n->left);
		deleteNodes(n->right);
		delete n;
	}

}

void BinarySearchTree::traversePreorder(BinaryTreeNode * n) {

	if (n == NULL)
		return;

	cout << "" << n->element << " ";
	this->traversePreorder(n->left);
	this->traversePreorder(n->right);
	
}

void BinarySearchTree::traverseInorder(BinaryTreeNode * n) {

	if (n == NULL)
		return;

	this->traverseInorder(n->left);
	cout << "" << n->element << " ";
	this->traverseInorder(n->right);


}

void BinarySearchTree::traversePostorder(BinaryTreeNode * n) {

	if (n == NULL)
		return;

	this->traversePostorder(n->left);
	this->traversePostorder(n->right);
	cout << "" << n->element << " ";

}
