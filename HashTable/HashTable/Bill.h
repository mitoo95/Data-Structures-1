#pragma once
#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Bill
{
	public:
		Bill();
		Bill(int, string, double);
		int getBillNumber();
		void setBillNumber(int);
		string getClientName();
		void setClientName(string);
		double getAmount();
		void setAmount(double);
		Bill* next;

	private:
		int billNumber;
		string clientName;
		double amount;

};

