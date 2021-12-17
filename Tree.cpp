#include "Tree.h"
#include <iostream>
#include <iomanip>
Tree::Tree() {
	root = nullptr;
	size = 0;
}
Node* Tree::getRoot() {
	return root;
}

void Tree::push(int val)
{
	if (root == nullptr) {
		root = new Node(val);
		size++;
	}
	else insert(root, val);
}

void Tree::insert(Node* subroot, int val) {
	if (subroot == nullptr) return;
	int subRootValue = subroot->getValue();
	if (val == subRootValue) return;
	if (val > subRootValue) {
		if (subroot->getRight() == nullptr) {
			Node* right_node = new Node(val);
			subroot->setRight(right_node);
			size++;
			return;
		}
		else insert(subroot->getRight(), val);
	}
	if (val < subRootValue) {
		if (subroot->getLeft() == nullptr) {
			Node* left_node = new Node(val);
			subroot->setLeft(left_node);
			size++;
			return;
		}
		else insert(subroot->getLeft(), val);
	}
}

void Tree::merge(Tree* A, Tree* B)
{
	insert_direct(A->getRoot()); //клонирование дерева A
	insert_direct(B->getRoot()); //вставка дерева B в прямом порядке
}

void Tree::insert_direct(Node* subroot) {
	if (subroot == nullptr) return;
	this->push(subroot->getValue());
	insert_direct(subroot->getLeft());
	insert_direct(subroot->getRight());
}

void Tree::print_direct() {
	if (root == nullptr) return;
	else print_direct(root);
}
void Tree::print_direct(Node* subroot)
{
	if (subroot == nullptr) return;
	std::cout << subroot->getValue() << ' ';
	print_direct(subroot->getLeft());
	print_direct(subroot->getRight());
}

void Tree::print_back() {
	if (root == nullptr) return;
	else print_back(root);
}
void Tree::print_back(Node* subroot)
{
	if (subroot == nullptr) return;
	print_back(subroot->getLeft());
	print_back(subroot->getRight());
	std::cout << subroot->getValue() << ' ';
}

void Tree::print_sym() {
	if (root == nullptr) return;
	else print_sym(root);
}
void Tree::print_sym(Node* subroot)
{
	if (subroot == nullptr) return;
	print_sym(subroot->getLeft());
	std::cout << subroot->getValue() << ' ';
	print_sym(subroot->getRight());
}