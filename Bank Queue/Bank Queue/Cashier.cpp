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

	if (isEmpty() == true) {
		
		head = c;
		tail = c;

	}
	else {

		//int typeACounter = 0;

		Customer *temp = head;
		Customer *temp2 = new Customer();

		//if priorityAccess is A
		if (c->getPriorityTicket() == 'A'){

			//if the head is anything other than A
			if (temp->getPriorityTicket() != 'A') {

				head = c;
				c->next = temp;
				return 1;

			}
			//if head is A and need to insert another A
			else if (temp->getPriorityTicket() == 'A') {

				while (temp->next->getPriorityTicket() == 'A') {
					temp = temp->next;

				}
				c->next = temp->next;
				temp->next = c;
				return 1;

			}
		}
		//Enqueuing an element B
		else if (c->getPriorityTicket() == 'B') {

			tail->next = c;
			tail = c;

		}
		//if we want to insert a Third priority [C] after 3 customers or after every A
		else if (c->getPriorityTicket() == 'C') {



		}
		//if we insert an Element D or better known as a A.5
		else if (c->getPriorityTicket() == 'D') {

			while (temp->getPriorityTicket() == 'A') {
				temp2 = temp;
				temp = temp->next;
			}

			temp2->next = c;
			c->next = temp;

		}
	}

	return 1;
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