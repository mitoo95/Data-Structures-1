#pragma once
#include "pch.h"
#include <iostream>
#include <string>

using namespace std;


enum opType {

	deposit = 0,
	withdrawal = 1,
	query = 2

};


class Customer {

	public:
		Customer();
		Customer(int, opType, char);
		string getOperationType();
		void setOperationType(opType);
		void setPriorityTicket(char);
		char getPriorityTicket();
		int getIdNumber();
		void setIdNumber(int);
		Customer *next;

	private:
		
		char priority;
		string operation;
		int id;
		
};