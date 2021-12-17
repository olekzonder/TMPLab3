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

void Tree::push(int val,int key)
{
	if (root == nullptr) {
		root = new Node(val,key);
		size++;
	}
	else insert(root, val,key);
}

void Tree::insert(Node* subroot, int val, int key) {
	if (subroot == nullptr) return;
	int subRootValue = subroot->getValue();
	if (val == subRootValue) return;
	if (val > subRootValue) {
		if (subroot->getRight() == nullptr) {
			Node* right_node = new Node(val,key);
			subroot->setRight(right_node);
			size++;
			return;
		}
		else if (subroot->getRight()->getKey() < key) {
			Node* temp = subroot->getRight();
			Node* right_node = new Node(val, key);
			subroot->setRight(right_node);
			if (temp->getRight() != nullptr && temp->getRight()->getValue() > right_node->getValue()) {
				right_node->setRight(temp->getRight());
				temp->setRight(nullptr);
			}
			right_node->setRight(temp);
			return;
		}
		else insert(subroot->getRight(), val,key);
	}
	if (val < subRootValue) {
		if (subroot->getLeft() == nullptr) {
			Node* left_node = new Node(val,key);
			subroot->setLeft(left_node);
			size++;
			return;
		}
		else if (subroot->getLeft()->getKey() < key) {
			Node* temp = subroot->getLeft();
			Node* left_node = new Node(val, key);
			subroot->setLeft(left_node);
			if (temp->getRight() != nullptr && temp->getRight()->getValue() > left_node->getValue()) {
				left_node->setRight(temp->getRight());
				temp->setRight(nullptr);
			}
			left_node->setLeft(temp);
			size++;
			return;
		}
		else insert(subroot->getLeft(), val,key);
	}
}

void Tree::merge(Tree* A, Tree* B)
{
	Tree::insert(A->getRoot());
	Tree::insert(B->getRoot());
}

void Tree::insert(Node* subroot) {
	if (subroot == nullptr) return;
	this->push(subroot->getValue(),subroot->getKey());
	insert(subroot->getLeft());
	insert(subroot->getRight());

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