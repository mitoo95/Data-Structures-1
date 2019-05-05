#include "pch.h"
#include "mangoTree.h"

mangoTree::mangoTree() {
	
	head = nullptr;
	tail = nullptr;
	mangoCounter = 0;

}

int mangoTree::getMangoCounter() {
	
	return mangoCounter;

}

void mangoTree::increaseCounter() {
	this->mangoCounter++;
}

void mangoTree::decreaseCounter() {
	this->mangoCounter--;
}

int mangoTree::addMangoFruit(mangoFruit *m) {
	
	if (mangoCounter == 0) {
		head = m;
		tail = m;
	}
	else {
		tail->next = m;
		m->prev = tail;
		tail = m;
	}
	increaseCounter();
	return 0;
}

int mangoTree::insertMangoFruit(mangoFruit *m, int position) {
	if (position > (this->getMangoCounter() + 1)) {
		return -1;

	}
	else if (position < 0) {
		return -2;
	}
	else if (position == (this->getMangoCounter() + 1)) {
		addMangoFruit(m);
		return 0;
	}
	else if (position <= getMangoCounter()) {
		mangoFruit* tmp = head;
		int actualPos = 1;
		while (actualPos < position) {
			actualPos++;
			tmp = tmp->next;
		}
		m->prev = tmp->prev;
		m->next = tmp;
		m->prev->next = m;
		tmp->prev = m;
		increaseCounter();
		return 0;
	}
	else if (position == 1) {

		mangoFruit *tmp = head;


	}
	return -3;
}

int mangoTree::deleteMangoFruit(int position) {
	if (position > this->getMangoCounter()) {
		return -1;

	}
	else if (position < 0) {
		return -2;
	}
	else if (position <= this->getMangoCounter()) {
		mangoFruit* tmp = head;
		int actualPos = 1;
		while (actualPos < position) {
			actualPos++;
			tmp = tmp->next;
		}
		if (tmp == head) {
			tmp->next->prev = nullptr;
			head = head->next;
		}
		else if (tmp == tail) {
			tmp->prev->next = nullptr;
			tail = tail->prev;
		}
		else {
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
		}
		delete tmp;
		decreaseCounter();
		return 0;
	}
	return -3;
}

void mangoTree::printMangoWeight() {

	mangoFruit *temp = new mangoFruit;
	temp = head;
	while (temp != nullptr) {
		cout << temp->getWeight() << "\t";
		temp = temp->next;
	}

}