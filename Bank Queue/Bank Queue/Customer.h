#pragma once
#include "pch.h"
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
		Customer(int, opType);
		string getOperationType();
		void setOperationType(opType);
		int getIdNumber();
		void setIdNumber(int);
		Customer *next;

	private:

		string operation;
		int id;
		
};