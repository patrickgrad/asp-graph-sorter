#include "graph.hpp"

using namespace std;

Graph::Graph()
{
	this->vcount = 0;
	this->edges = vector<Edge*>();
}
		
Graph Graph::deep_copy()	//iterate through our edges and copy edge and vertex information into a new graph whose address is returned
{
	Graph new_graph;
	vector<Edge*> new_graph_edges = vector<Edge*>();

	new_graph.set_vcount(this->vcount);

	for(int i = 0; i < this->edges.size(); i++)
	{
		Edge *e = new Edge();
		for(int ii = 0; ii < i; ii++)
		{
			if(this->edges.at(i)->get_v1() == this->edges.at(ii)->get_v1())
			{
				e->set_v1(new_graph_edges.at(ii)->get_v1());
			}	

			if(this->edges.at(i)->get_v1() == this->edges.at(ii)->get_v2())
			{
				e->set_v1(new_graph_edges.at(ii)->get_v2());
			}

			if(this->edges.at(i)->get_v2() == this->edges.at(ii)->get_v1())
			{
				e->set_v2(new_graph_edges.at(ii)->get_v1());
			}

			if(this->edges.at(i)->get_v2() == this->edges.at(ii)->get_v2())
			{
				e->set_v2(new_graph_edges.at(ii)->get_v2());
			}
		}

		if(e->get_v1() == NULL)
			e->set_v1(this->edges.at(i)->get_v1()->deep_copy());

		if(e->get_v2() == NULL)
			e->set_v2(this->edges.at(i)->get_v2()->deep_copy());

		new_graph_edges.push_back(e);   //now push into edges vector
	}

	new_graph.set_edges(new_graph_edges);

	return new_graph;
}

int Graph::min_cut(int stop)  //uses Karger's algorithm to consolidate the graph to the number of nodes given by stop, returns the minimum cut
{
	//while vertex count is greater than our stopping point
	while(this->vcount > stop)
	{
		//generate random number that represents index of edges array in graph
		int index = rand() % this->edges.size();
		Edge *e = this->edges.at(index);

		Vertex *v1 = e->get_v1();
		Vertex *v2 = e->get_v2();

		//make sure edge isn't a loop
		if(v1 != v2)
		{
			//merge the data from v1 into v2 
			vector<Person*> v1_persons = v1->get_persons();
			vector<Person*> v2_persons = v2->get_persons();

			v2_persons.insert(v2_persons.end(), v1_persons.begin(), v1_persons.end());

			v2->set_persons(v2_persons);

			//loop though edges and find all the connections that point to v1 and set to v2 instead
			for(int i = 0; i < this->edges.size(); i++)
			{
				Edge *ee = this->edges.at(i);

				if(ee->get_v1() == v1)
					ee->set_v1(v2);

				if(ee->get_v2() == v1)
					ee->set_v2(v2);
				
			}

			//delete v1
			delete v1;
			(this->vcount)--;

			//delete edge and remove from list of edges
			this->edges.erase(edges.begin()+index);
			delete e;
		}

		//if edge is a loop delete the edge
		else
		{
			this->edges.erase(edges.begin()+index);
			delete e;
		}

	}

	//loop though edges and make sure we don't have an edge loop
	for(int i = 0; i < this->edges.size(); i++)
	{
		Edge *e = this->edges.at(i);

		if(e->get_v1() == e->get_v2())
		{
			// cout << "true " << e->get_v1() << " " << e->get_v2() << endl;
			this->edges.erase(edges.begin()+i);
			delete e;
		}

		// else
		// {
		// 	cout << "false " << e->get_v1() << " " << e->get_v2() << endl;
		// }
		
	}

	return this->edges.size();
}

vector<Edge*> Graph::get_edges()
{
	return this->edges;
}

void Graph::set_edges(vector<Edge*> edges)
{
	this->edges = edges;
}

int Graph::get_vcount()
{
	return this->vcount;
}

void Graph::set_vcount(int vcount)
{
	this->vcount = vcount;
}

void Graph::print()	//prints the graph
{
	cout << "TODO: print graph";
}