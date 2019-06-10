#include <iostream>
#include "pch.h"
#include "Hash.h"
#include "Bill.h"
#include <string>

using namespace std;

int main(){

	Bill *b = new Bill(252, "Erasmo", 100.00);
	Hash h;
	int billNum = 0;
	h.addItem(b);
	//h.printTable();
	
	while (billNum != -1) {

		cout << "Search for bill #: ";
		cin >> billNum;
		if (billNum != -1) {
			h.findBill(billNum);
		}

	}

	return 0;

}