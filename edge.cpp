#include "edge.hpp"

using namespace std;

Edge::Edge()
{
	this->v1 = NULL;
	this->v2 = NULL;
}

Edge::Edge(Vertex *v1, Vertex *v2)
{
	this->v1 = v1;
	this->v2 = v2;
}

Edge* Edge::deep_copy()
{
	Vertex *new_v1 = this->v1->deep_copy();
	Vertex *new_v2 = this->v2->deep_copy();

	return new Edge(new_v1, new_v2);
}

Vertex* Edge::get_v1()
{
	return this->v1;
}

Vertex* Edge::get_v2()
{
	return this->v2;
}

void Edge::set_v1(Vertex *v)
{
	this->v1 = v;
}

void Edge::set_v2(Vertex *v)
{
	this->v2 = v;
}