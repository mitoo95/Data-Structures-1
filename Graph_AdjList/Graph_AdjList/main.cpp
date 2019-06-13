#include <iostream>
#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"


using namespace std;

int main() {

	// array of graph edges as per above diagram.
	Edge edges[] =
	{
		// pair (x, y) represents edge from x to y
		{ 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
		{ 3, 2 }, { 4, 5 }, { 5, 4 }
	};

	// Number of vertices in the graph
	int N = 6;

	// calculate number of edges
	int n = sizeof(edges) / sizeof(edges[0]);

	// construct graph
	Graph graph(edges, n, N);

	// print adjacency list representation of graph
	for (int i = 0; i < N; i++)
	{
		// print given vertex
		cout << i << " --";

		// print all its neighboring vertices
		graph.printList(graph.head[i]);
	}

	return 0;

}