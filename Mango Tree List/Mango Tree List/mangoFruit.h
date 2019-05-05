#pragma once
#include "pch.h"
#include <iostream>

class mangoFruit {

	public:
		mangoFruit ();
		mangoFruit(double);
		double getWeight();
		void setWeight(double);
		mangoFruit *next;
		mangoFruit *prev;
		

	private:
		
		double weight;
};