#include "pch.h"
#include "Customer.h"
#include <stdlib.h>
#include <time.h>


Customer::Customer() {

	setIdNumber(0);
	next = nullptr;

}

Customer::Customer(int t, opType op) {

	setIdNumber(t);
	setOperationType(op);
	next = nullptr;

}

int Customer::getIdNumber() {

	return id;

}

void Customer::setIdNumber(int t) {

	id = t;

}

string Customer::getOperationType() {

	return operation;

}

void Customer::setOperationType(opType ot) {

	srand(time(NULL));
	int rd = rand() % 3;

	if (rd == 0) {

		ot = deposit;
		operation = "Deposit";

	}
	else if (rd == 1) {

		ot = withdrawal;
		operation = "Withdrawal";

	}
	else {

		ot = query;
		operation = "Query";

	}

}