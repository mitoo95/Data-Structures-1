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
		c->next = nullptr;

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
			//Enqueuing newcoming A's
			else if (temp->getPriorityTicket() == 'A') {

				while (temp->getPriorityTicket() == 'A' && temp->next != nullptr && temp->next->getPriorityTicket() == 'A') {
					
					temp = temp->next;

				}
				c->next = temp->next;
				temp->next = c;
				return 1;
				

			}
		}
		//Enqueuing an element B
		else if (c->getPriorityTicket() == 'B') {

			while (temp->next != nullptr) {
				temp = temp->next;
			}
			tail = temp;
			tail->next = c;
			tail = c;
			return 1;

		}
		//if we want to insert a Third priority [C] after 3 customers or after every A
		else if (c->getPriorityTicket() == 'C') {



		}
		//if we insert an Element D or better known as a A.5
		else if (c->getPriorityTicket() == 'D') {
			if (temp->getPriorityTicket() != 'A' && temp->getPriorityTicket() != 'D') {

				head = c;
				c->next = temp;
				return 1;

			}
			/*else if ((temp->getPriorityTicket() == 'A' || temp->getPriorityTicket() == 'D') && temp->next == nullptr) {

				temp->next = c;
				c->next = nullptr;
				tail = c;
				return 1;

			}*/
			else if (temp->getPriorityTicket() == 'A' || temp->getPriorityTicket() == 'D') {

				while ((temp->getPriorityTicket() == 'A' || temp->getPriorityTicket() == 'D') && temp->next != nullptr && 
					(temp->next->getPriorityTicket() == 'A' || temp->next->getPriorityTicket() == 'D')) {
					
					temp = temp->next;

				}
				c->next = temp->next;
				temp->next = c;
				return 1;

			}

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

	if (head == nullptr && tail == nullptr) {
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

		while (temp != nullptr) {

			cout << temp->getIdNumber() << endl;
			cout << temp->getOperationType() << endl;
			cout << temp->getPriorityTicket() << endl;
			cout << " ------------ " << endl;
			temp = temp->next;
		}

	}

}