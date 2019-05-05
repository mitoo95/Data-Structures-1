#pragma once
#include "pch.h"
#include <iostream>
#include "mangoFruit.h"

using namespace std;

class mangoTree{

	public:
		mangoTree();
		int addMangoFruit(mangoFruit *);
		int insertMangoFruit(mangoFruit *, int);
		int deleteMangoFruit(int);
		void printMangoWeight();
		int getMangoCounter();
		mangoFruit *head;
		mangoFruit *tail;


	private:

		void increaseCounter();
		void decreaseCounter();
		int mangoCounter;
		
};