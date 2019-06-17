#include "Graph.h"



Graph::Graph() {

	h = nullptr;

}


Graph::~Graph() {



}

bool Graph::isEmpty() {

	if (h == nullptr) {
		return true;
	}
	else {
		return false;
	}

}

int Graph::size() {

	int counter = 0;
	Vertex *aux;
	aux = h;

	while (aux != nullptr) {

		counter++;
		aux = aux->next;

	}
	return counter;
}

Vertex *Graph::getVertex(string name) {

	Vertex *aux;
	aux = h;
	while (aux != nullptr) {

		if (aux->getName() == name) {

			return aux;

		}
		aux = aux->next;
	}
	return nullptr;
}

void Graph::addVertex(string name) {

	Vertex *nVertex = new Vertex(name);

	if (isEmpty() == true) {

		h = nVertex;

	}
	else {

		Vertex *aux = h;
		while (aux->next != nullptr) {

			aux = aux->next;

		}
		aux->next = nVertex;

	}

}

void Graph::addEdge(Vertex *origin, Vertex *dest, int weight) {

	Edge *nEdge = new Edge(weight);

	Edge *aux = origin->adj;

	if (aux == nullptr) {

		origin->adj = nEdge;
		nEdge->adj = dest;

	}
	else {

		while (aux->next != nullptr) {

			aux = aux->next;

		}
		aux->next = nEdge;
		nEdge->adj = dest;

	}
}

void Graph::adjList() {

	Vertex *vertAux;
	Edge * edgeAux;

	vertAux = h;

	while (vertAux != nullptr) {

		cout << vertAux->getName() << "->";
		edgeAux = vertAux->adj;
		while (edgeAux != nullptr) {

			cout << edgeAux->adj->getName() << "->";
			edgeAux = edgeAux->next;

		}
		vertAux = vertAux->next;
		cout << endl;
	}
}

void imprimirMatrizAdyacencia() {
	
	Vertex *vertAux;
	Edge * edgeAux;

}

void Graph::Nullify() {

	Vertex *aux;

	while (h != nullptr) {

		aux = h;
		h = h->next;
		delete aux;

	}
}

void Graph::deleteEdge(Vertex *origin, Vertex *dest) {

	Edge *temp = new Edge();
	Edge *temp2 = new Edge();
	int band = 0;

	temp = origin->adj;

	if (temp == nullptr) {

		cout << "The origin vertex does not have edges" << endl;

	}
	else if (temp->adj == dest) {

		origin->adj = temp->next;
		delete temp;

	}
	else {

		while (temp != nullptr) {

			if (temp->adj == dest) {
				
				band = 1;
				temp2->next = temp->next;
				delete temp;
				break;

			}
			temp2 = temp;
			temp = temp->next;
		}
		if (band == 0) {

			cout << "The origin and destination vertices are not connected" << endl;

		}
	}
}

void Graph::deleteVertex(Vertex *vert) {

	Vertex *temp = new Vertex();
	Vertex *temp2 = new Vertex();
	Edge *aux;

	temp = h;

	while (temp != nullptr) {

		aux = temp->adj;
		while (aux != nullptr) {

			if (aux->adj == vert) {
				deleteEdge(temp, aux->adj);
				break;
			}
			aux = aux->next;
		}

		temp = temp->next;
	}

	temp = h;
	if (h == vert) {

		h = h->next;
		delete temp;
	}
	else {

		while (temp != vert) {
			temp2 = temp;
			temp = temp->next;
		}
		temp2->next = temp->next;
		delete temp;
	}
}

void Graph::depthPath(Vertex *origin) {

	int band, band2;
	Vertex *temp;
	stack<Vertex*> stck;
	list<Vertex*> lst;
	list<Vertex*>::iterator i;

	stck.push(origin);

	while (!stck.empty()) {

		band = 0;
		temp = stck.top();
		stck.pop();

		for (i = lst.begin(); i != lst.end(); i++) {

			if (*i == temp) {

				band = 1;

			}

		}

		if (band == 0) {

			cout << temp->getName() << ", ";
			lst.push_back(temp);

			Edge *aux;
			aux = temp->adj;

			while (aux != nullptr) {
				
				band2 = 0;
				for (i = lst.begin(); i != lst.end(); i++) {

					if (*i == aux->adj) {
						band2 = 1;
					}

				}
				if (band2 == 0) {

					stck.push(aux->adj);

				}
				aux = aux->next;
			}

		}

	}
}