#pragma once
#include <iostream>

using namespace std;

class Node {
	
	public:
		Node();
		Node(int);
		~Node();
		int getVal();
		void setVal(int);
		Node* next;

	private:
		int val;

};

