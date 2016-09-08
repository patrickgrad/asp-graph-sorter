#ifndef EDGE_H
#define EDGE_H

#import "vertex.hpp"

using namespace std;

class Edge
{
	public:
		Edge();
		Edge(Vertex *v1, Vertex *v2);
		Edge* deep_copy();
		Vertex* get_v1();
		Vertex* get_v2();
		void set_v1(Vertex *v); //make sure to not lose the things that v1 and v2 point to before we change the pointers
		void set_v2(Vertex *v);

	private:
		Vertex *v1;		//each Edge can only be connected to 2 other verticies, however a vertex can be connected to an unlimited number of edges
		Vertex *v2;
};

#endif