#include "Edge.h"


Edge::Edge() {

	setSrc(NULL);
	setDest(NULL);

}

Edge::Edge(int s, int d) {

	setSrc(s);
	setDest(d);

}

Edge::~Edge()
{
}

int Edge::getSrc(){

	return src;

}

void Edge::setSrc(int _src){

	src = _src;

}

int Edge::getDest(){

	return dest;

}

void Edge::setDest(int _dest){

	dest = _dest;

}