#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include "Bill.h"

using namespace std;

class Hash{

	static const int tableSize = 10;
	Bill *HashTable[tableSize];

	public:
		Hash();
		~Hash();
		Hash(int, string, double);
		void addItem(Bill*);
		int numItemsIndex(int);
		void printTable();
		void printItemsIndex(int);
		void findBill(int);
		void removeBill(int);
		

	private:
		//int hashFunctionInt(int key);
		int hashFunction(string key);
		
};