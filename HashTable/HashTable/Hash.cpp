#include "pch.h"
#include <iostream>
#include <string>
#include "Hash.h"

using namespace std;

Hash::Hash() {

	//fill whole array with default Bill nodes
	for (int i = 0; i < tableSize; i++) {

		HashTable[i] = new Bill();

	}

}

Hash::~Hash()
{
	Bill *ptr;
	for (int i = 0; i < tableSize; i++)
	{
		while (HashTable[i] != NULL)
		{
			ptr = HashTable[i];
			HashTable[i] = HashTable[i]->next;
			delete ptr;
		}
	}
}


/*int Hash::hashFunctionInt(int key) {

	int hash = 0;
	int num = 0;

	num = key;
	while (num != 0) {

		hash = (hash + num % 10) % tableSize;
		num = num / 10;

	}

	return hash;

}*/


int Hash::hashFunction(string key) {

	int hash = 0;
	int index;

	//for loop that goes from key start to end
	for (int i = 0; i < key.length(); i++) {

		//hash = hash + ASCII code of characters in key
		hash = hash + (int)key[i];

	}

	//index = hash mod of tablesize
	index = hash % tableSize;

	return index;

}

void Hash::addItem(Bill *n) {

	string s = to_string(n->getBillNumber());
	int index = hashFunction(s);

	// if billNumber element in HT[i] == 0 meaning no item
	if (HashTable[index]->getBillNumber() == 0) {

		//insert node in H[i]
		HashTable[index] = n;

	}
	else {

		// create temp pointer that points at first item
		Bill *ptr = HashTable[index];
		//while ptr->next is different from null
		while (ptr->next != nullptr) {
			//ptr points to next item
			ptr = ptr->next;
		}
		//when pointer points to null insert node
		ptr->next = n;

	}

}

int Hash::numItemsIndex(int index) {

	int count = 0;

	// if billNumber element in HT[i] == 0 meaning no item
	if (HashTable[index]->getBillNumber() == 0) {

		return count;

	}
	else {
		//+1 to count
		count++;
		// create ptr to first item in index
		Bill *ptr = HashTable[index];
		//while ptr->next different from null, add to count and move ptr to next
		while (ptr->next != nullptr) {
			count++;
			ptr = ptr->next;
		}
	}
	return count;

}

void Hash::printTable() {

	int num;

	// for loop until i = tableSize
	for (int i = 0; i < tableSize; i++) {

		//num = items in index(i), print all the first items of index and how many more are there inside index
		num = numItemsIndex(i);
		cout << "-------------\n";
		cout << "Index: " << i << endl;
		cout << HashTable[i]->getBillNumber() << endl;
		cout << HashTable[i]->getClientName() << endl;
		cout << HashTable[i]->getAmount() << endl;
		cout << "Number of items: " << num << endl;

	}

}

void Hash::printItemsIndex(int index) {

	//ptr to first item on index
	Bill *ptr = HashTable[index];

	//if bill number is 0 print hashtable is empty
	if (ptr->getBillNumber() == 0) {

		cout << "Index: " << index << " is empty";

	}
	// else index has items
	else {
		//print index number
		cout << "Index: " << index << "contains the following item(s)\n";

		//while loop to traverse index items, and print them
		while (ptr != nullptr) {

			cout << "--------------\n";
			cout << ptr->getBillNumber() << endl;
			cout << ptr->getClientName() << endl;
			cout << ptr->getAmount() << endl;
			ptr = ptr->next;

		}
	}

}

void Hash::findBill(int bN) {

	// convert key thats an int to string and use hashfunction
	string s = to_string(bN);
	int index = hashFunction(s);

	//create 3 vars one bool, one string and a double
	bool foundBill = false;
	string name;
	double amount;

	//ptr to first item on index
	Bill *ptr = HashTable[index];
	//while loop to traverse and verify if bN is equal to bill number of pointer
	while (ptr != nullptr) {

		if (ptr->getBillNumber() == bN) {

			foundBill = true;
			name = ptr->getClientName();
			amount = ptr->getAmount();

		}
		ptr = ptr->next;
	}
	//if bill is found print client name and amount
	if (foundBill == true) {

		cout << "Client Name: " << name << endl;
		cout << "Amount: " << amount << endl;

	}
	//if bill not found print bN not found
	else {

		cout << "Bill " << bN << " not found\n";

	}

}

void Hash::removeBill(int bN) {

	// convert key thats an int to string and use hashfunction
	string s = to_string(bN);
	int index = hashFunction(s);

	//create 3 pointers
	Bill *delPtr;
	Bill *p1;
	Bill *p2;

	// Case 0 - bucket is empty
	if (HashTable[index]->getBillNumber() == 0) {

		// bill number not found
		cout << bN << " was not found\n";

	}

	// Case 1 - only 1 item on bucket and matches with key
	else if (HashTable[index]->getBillNumber() == bN && HashTable[index]->next == nullptr) {

		//replace found Bill with default Bill
		HashTable[index] = new Bill();
		cout << bN << " was removed from HashTable\n";

	}

	// Case 2 - match is first item and there are more items
	else if (HashTable[index]->getBillNumber() == bN) {

		// point delptr to first item in index
		delPtr = HashTable[index];
		//move index pointer to next
		HashTable[index] = HashTable[index]->next;
		//delete delptr
		delete delPtr;

		cout << bN << " was removed from HashTable\n";
	}

	// Case 3 - bucket has items but first item is not match
	else {

		//point p1 to next index item
		p1 = HashTable[index]->next;
		//point p2 to first index item
		p2 = HashTable[index];

		while (p1 != NULL && p1->getBillNumber() != bN) {

			p2 = p1;
			p1 = p1->next;
		}
		// Case 3.1 - no match
		if (p1 == nullptr) {

			cout << bN << " was not found\n";

		}
		// Case 3.2 - match found
		else {

			delPtr = p1;
			p1 = p1->next;
			p2->next = p1;

			delete delPtr;
			cout << bN << " was removed from HashTable\n";
		}
	}

}