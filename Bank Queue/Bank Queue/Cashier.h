#pragma once
#include "pch.h"
#include <iostream>
#include "Customer.h"

class Cashier {

	public:
		Cashier();
		int Enqueue(Customer *);
		int Dequeue();
		int getCounter();
		bool isEmpty();
		void print();
		Customer *head;
		Customer *tail;

	private:

		void increaseCounter();
		void decreaseCounter();
		int counter;

};