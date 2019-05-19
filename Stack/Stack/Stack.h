#pragma once
#include "pch.h"
#include "Node.h"

class Stack {

	public:
		Stack();
		bool push(Node *);
		Node *pop();
		Node *top;
		int counter, size;

	private:


};