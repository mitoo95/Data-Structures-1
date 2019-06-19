#pragma once
class Element {

	public:
		Element();
		Element(int);
		~Element();
		int getKey();
		void setKey(int);
		Element *left;
		Element *right;

	private:
		int key;

};

