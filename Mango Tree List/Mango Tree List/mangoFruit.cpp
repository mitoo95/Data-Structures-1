#include "pch.h"
#include "mangoFruit.h"

mangoFruit::mangoFruit(double w) {

	setWeight(w);
	next = nullptr;
	prev = nullptr;

}

mangoFruit::mangoFruit() {
	
	setWeight(0);
	next = nullptr;
	prev = nullptr;

}

void mangoFruit::setWeight(double w) {

	weight = w - (0.1 * w);

}

double mangoFruit::getWeight() {

	return weight;

}