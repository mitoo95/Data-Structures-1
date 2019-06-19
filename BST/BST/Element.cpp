#include "Element.h"



Element::Element() {

	setKey(-1);
	left = nullptr;
	right = nullptr;

}

Element::Element(int _key) {

	setKey(_key);
	left = nullptr;
	right = nullptr;

}

Element::~Element() {



}

int Element::getKey(){

	return key;

}

void Element::setKey(int _key) {

	key = _key;

}