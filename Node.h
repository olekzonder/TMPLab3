#pragma once
#include <vector>
class Node
{
private:
	Node* root;
	Node* left;
	Node* right;
	int value;
public:
	Node();
	Node(int val);
	Node* getLeft();
	Node* getRight();
	void setLeft(Node* newson);
	void setRight(Node* newson);
	void setValue(int value);
	int getValue();
};

