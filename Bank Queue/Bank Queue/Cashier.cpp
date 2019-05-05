#include "pch.h"
#include "Cashier.h"

using namespace std;

Cashier::Cashier() {

	head = nullptr;
	tail = nullptr;
	counter = 0;

}

int Cashier::getCounter() {

	return counter;

}

void Cashier::increaseCounter() {

	counter++;

}

void Cashier::decreaseCounter() {

	counter--;

}

int Cashier::Enqueue(Customer *c) {

	if (isEmpty()) {

		head = c;
		tail = c;

	}
	else {

		tail->next = c;
		tail = c;
		c->next = nullptr;

	}
	increaseCounter();
	return 0;

}

int Cashier::Dequeue() {

	Customer *c = new Customer();

	if (isEmpty()) {

		cout << "Queue is empty" << endl;
		return -2;
	}
	else {

		c = head;
		cout << "\nDequeing: " << c->getIdNumber() << endl;
		head = c->next;
		c->next = nullptr;
		delete c;

		decreaseCounter();
		return 0;

	}

}

bool Cashier::isEmpty() {

	if (counter == 0) {
		return true;
	}
	else {
		return false;
	}

}

void Cashier::print() {

	Customer *temp = new Customer;
	temp = head;

	if (head == nullptr && tail == nullptr) {

		cout << "Emtpy queue" << endl;

	}
	else {

		while (temp != NULL) {

			cout << temp->getIdNumber() << endl;
			cout << temp->getOperationType() << endl;
			temp = temp->next;
		}

	}

}