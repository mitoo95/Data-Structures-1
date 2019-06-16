#pragma once
#include <iostream>
class Vertex;

using namespace std;


class Edge {

	public:
		Edge();
		Edge(int);
		~Edge();
		Edge *next;
		Vertex *adj;
		int getWeight();
		void setWeight(int);
	
	private:
		int weight;

};

