#include "pch.h"
#include "Bill.h"


Bill::Bill() {

	setBillNumber(0);
	setClientName("empty");
	setAmount(0.0);
	next = nullptr;

}

Bill::Bill(int num, string name, double amount) {

	setBillNumber(num);
	setClientName(name);
	setAmount(amount);
	next = nullptr;

}

int Bill::getBillNumber() {

	return billNumber;

}

void Bill::setBillNumber(int bN) {

	billNumber = bN;

}

string Bill::getClientName() {

	return clientName;

}

void Bill::setClientName(string cN) {

	clientName = cN;

}

double Bill::getAmount() {

	return amount;

}

void Bill::setAmount(double a) {

	amount = a;

}