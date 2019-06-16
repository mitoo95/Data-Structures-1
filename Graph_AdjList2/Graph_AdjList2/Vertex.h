#pragma once
#include <iostream>
class Edge;

using namespace std;

class Vertex {
	
	public:
		Vertex();
		Vertex(string);
		~Vertex();
		Vertex *next;
		Edge *adj;
		string getName();
		void setName(string);
	
	private:
		string name;

};

