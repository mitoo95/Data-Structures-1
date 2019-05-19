#include "pch.h"
#include "Stack.h"


Stack::Stack() {

	top = nullptr;
	size = 5;
	counter = 0;

}


bool Stack::push(Node *n) {

	if (top == nullptr) {

		top = n;
		counter++;
		return true;
	}
	else {
		if (counter < size) {
			n->next = top;
			top = n;
			counter++;
			return true;
		}
	}
	return false;

}

Node* Stack::pop() {

	Node *temp = new Node();

	if (top == nullptr) {

		return nullptr;

	}
	else {

		temp = top;
		top = temp->next;
		temp->next = nullptr;
		counter--;
		return temp;

	}
}