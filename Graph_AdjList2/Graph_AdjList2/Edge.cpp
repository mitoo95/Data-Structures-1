#include "Edge.h"



Edge::Edge()
{
	setWeight(0);
	next = nullptr;
	adj = nullptr;

}

Edge::Edge(int w)
{
	setWeight(w);
	next = nullptr;
	adj = nullptr;

}

Edge::~Edge()
{
}

int Edge::getWeight() {

	return weight;

}

void Edge::setWeight(int w) {

	weight = w;

}