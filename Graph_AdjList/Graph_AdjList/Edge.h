#pragma once
#include <iostream>

using namespace std;

class Edge {

	public:
		Edge();
		Edge(int, int);
		~Edge();
		int getSrc();
		void setSrc(int);
		int getDest();
		void setDest(int);

	private:
		int src;
		int dest;
};

