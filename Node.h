#pragma once
#include <vector>
class Node
{
private:
	Node* left;
	Node* right;
	int value;
	int w;
public:
	Node();
	Node(int val,int key);
	Node* getLeft();
	Node* getRight();
	void setLeft(Node* newson);
	void setRight(Node* newson);
	void setValue(int value);
	int getValue();
	int getKey();
};

