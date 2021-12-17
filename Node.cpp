#include "Node.h"
Node::Node() { //Корень дерева
	left = nullptr;
	right = nullptr;
}

Node::Node(int val) {
	value = val;
	left = nullptr;
	right = nullptr;
}

Node* Node::getLeft() {
	return left;
}

Node* Node::getRight() {
	return right;
}

void Node::setLeft(Node* newson) {
	left = newson;
}

void Node::setRight(Node* newson) {
	right = newson;
}

void Node::setValue(int val) {
	value = val;
}
int Node::getValue() {
	return value;
}