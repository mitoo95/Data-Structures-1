#include "Vertex.h"


Node::Node() {

	setVal(NULL);
	next = nullptr;

}

Node::Node(int v) {

	setVal(v);
	next = nullptr;

}

Node::~Node()
{
}

int Node::getVal() {

	return val;

}

void Node::setVal(int _val) {

	val = _val;

}