#include "Graph.h"



Graph::Graph() {

	numV = NULL;
	head = nullptr;

}

Graph::Graph(Edge edges[], int n, int N) {

	// allocate memory
	head = new Node*[N]();
	numV = N;

	// initialize head pointer for all vertices
	for (int i = 0; i < N; i++)
		head[i] = nullptr;

	// add edges to the directed graph
	for (unsigned i = 0; i < n; i++)
	{
		int src = edges[i].getSrc();
		int dest = edges[i].getDest();

		// insert in the beginning
		Node* newNode = getAdjListNode(dest, head[src]);

		// point head pointer to new node
		head[src] = newNode;

		/*// Undirected graph
		newNode = getAdjListNode(src, head[dest]);

		// change head pointer to point to the new node
		head[dest] = newNode;*/

	}

}

Graph::~Graph() {

	for (int i = 0; i < numV; i++)
		delete[] head[i];

	delete[] head;

}

// Function to allocate new node of Adjacency List
Node* Graph::getAdjListNode(int dest, Node* head) {
	Node* newNode = new Node();
	newNode->setVal(dest);

	// point new node to current head
	newNode->next = head;

	return newNode;
}

// print all neighboring vertices of given vertex
void Graph::printList(Node* ptr)
{
	while (ptr != nullptr)
	{
		cout << " -> " << ptr->getVal() << " ";
		ptr = ptr->next;
	}
	cout << endl;
}