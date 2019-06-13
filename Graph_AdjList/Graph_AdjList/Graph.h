#pragma once
#include <iostream>
#include "Vertex.h"
#include "Edge.h"

class Graph {

	public:
		Graph();
		Graph(Edge[], int, int);
		void printList(Node* ptr);
		~Graph();
		Node **head; // An array of pointers to Node to represent adjacency list

	private:
		Node* getAdjListNode(int, Node*);
		int numV;  // number of vertices in the graph

};

