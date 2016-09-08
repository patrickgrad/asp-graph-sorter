#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <cstdlib>
#include <iostream>
#include "edge.hpp"
#include "vertex.hpp"
#include "person.hpp"

using namespace std;

class Graph
{
	public:
		Graph();
		Graph deep_copy();	//iterate through our edges and copy edge and vertex information into a new graph whose address is returned
		int min_cut(int stop);  //uses Karger's algorithm to consolidate the graph to the number of nodes given by stop, returns guess for minimum cut
		void print();	//prints the graph

		vector<Edge*> get_edges();
		void set_edges(vector<Edge*> edges);

		int get_vcount();
		void set_vcount(int vcount);


	private:
		int vcount;
		vector<Edge*> edges; //the vector of all edges of the graph, need to be able to access these easily
};

#endif