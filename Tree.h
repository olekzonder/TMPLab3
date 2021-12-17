#pragma once
#include "Node.h"
#include <iostream>
class Tree
{
private:
	unsigned int size;
	Node* root;
	void insert(Node* subroot, int val);
	void print_direct(Node* subroot);
	void print_back(Node* subroot);
	void print_sym(Node* subroot);
	void insert_direct(Node* subroot);
protected:
	Node* getRoot();
public:
	explicit Tree();

	void push(int);
	void print_direct();
	void print_back();
	void print_sym();
	void merge(Tree* A, Tree* B);
};

