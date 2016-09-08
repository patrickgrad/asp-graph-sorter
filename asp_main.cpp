#include <vector>
#include <iostream>
#include <fstream>

#include "person.hpp"
#include "vertex.hpp"
#include "graph.hpp"
#include "edge.hpp"

vector<Person> load_data(char* path);
void save_data(vector<Person*>* g1,vector<Person*>* g2);

string to_string(Vertex v);
string to_string(Person p);

int main(int argc, char* argv[])
{
	char* arg;
	char def[9] = "data.csv";

	srand(time(NULL));

	if(argc >= 2)
		arg = argv[1];
	else
		arg = def;

	vector<Person> people;
		
	try
	{
		people = load_data(arg);
	}
	catch(string e)
	{
		cout << e << endl;
	}

	/*
							 PAT
							/   
						SALLY<->DAVID 

		Min cut is betweeen Pat and Sally and is equal to 1
	*/


	Graph g = Graph();
	g.set_vcount(people.size());

	for(int i = 0; i < people.size(); i++)	//make all of our verticies before we start trying to link them, makes it easier to avoid erroneous duplicate verticies for the same person 
	{
		vector<Person*> persons = vector<Person*>();
		persons.push_back(&(people.at(i)));
	 	Vertex* new_person = new Vertex(persons);
	 	
	 	people.at(i).set_home(new_person); //make sure each person knows what his home vertex is for linking edges in the next step
	}

	//This section is :(
	//Can I restructure the data to avoid this much loopage? 
	for(int i = 0; i < people.size(); i++)
	{	
	 	for(int ii = 0; ii < people.at(i).get_name_list().size(); ii++)
	 	{
	 		for(int a = 0; a < people.size(); a++)
	 		{
	 			if(a != i && people.at(a).get_name() == people.at(i).get_name_list().at(ii))  //if we find a person in our overall list that is also in a person's list we need to make the edge between them
	 			{
	 				Edge* e = new Edge(people.at(a).get_home(), people.at(i).get_home());	//create the edge between the person we are looking at and their friend
	 				vector<Edge*> edg = g.get_edges();
	 				edg.push_back(e);
	 				g.set_edges(edg);	//save edge in Graph object
	 			}
	 		}
	 	}
	}

	int min = 999999;
	vector<Person*> group1;
	vector<Person*> group2;

	// for(int i = 0; i < g.get_edges().size(); i++)
	// {
	//  	cout << to_string(*(g.get_edges().at(i)->get_v1())) + " " << g.get_edges().at(i)->get_v1() << " : " << to_string(*(g.get_edges().at(i)->get_v2())) + " " << g.get_edges().at(i)->get_v2() << endl;
	// }

	for(int i = 0; i < 20*g.get_edges().size()*g.get_edges().size(); i++) //20*g.get_edges().size()*g.get_edges().size()
	{
	 	Graph gg = g.deep_copy();

	 	int m = gg.min_cut(2);

	 	// for(int i = 0; i < gg.get_edges().size(); i++)
	 	// {
	 	// 	cout << to_string(*(gg.get_edges().at(i)->get_v1())) + " " << gg.get_edges().at(i)->get_v1() << " : " << to_string(*(gg.get_edges().at(i)->get_v2())) + " " << gg.get_edges().at(i)->get_v2() << endl;
	 	// }

	 	// cout << gg.get_edges().size() << " ";

		if(m < min)
		{
			min = m;
			group1 = gg.get_edges().at(0)->get_v1()->get_persons();
			group2 = gg.get_edges().at(0)->get_v2()->get_persons();
		}

		// cout << i << endl;
	}

	cout << "Group 1: " << endl;

	for(int i = 0; i < group1.size(); i++)
	{
		cout << to_string(*(group1.at(i))) << endl;
	}

	cout << endl;

	cout << "Group 2: " << endl;

	for(int i = 0; i < group2.size(); i++)
	{
		cout << to_string(*(group2.at(i))) << endl;
	}

	cout << endl;

	save_data(&group1,&group2);

	return 0;
}

void save_data(vector<Person*>* g1,vector<Person*>* g2)
{
	ofstream stream("output.csv");

	if(stream.is_open())
    {
		int i = 0, ii = 0;

		stream << "Group 1, Group 2\n";

		while(i < g1->size() || ii < g2->size())
		{
			if(i < g1->size())
			{
				stream << g1->at(i)->get_name() + ",";
				i++;
			}

			else
			{
				stream << ",";
			}

			if(ii < g2->size())
			{
				stream << g2->at(ii)->get_name() + "\n";
				ii++;
			}

			else
			{
				stream << "\n";
			}

			
		}

    	stream.close();
    }

    else
    {
    	throw "Output file couldn't be saved.";
    }
}

vector<Person> load_data(char* path)
{
	ifstream stream(path);
    vector<Person> people;

    if(stream.is_open())
    {
    	string buff;

    	while(!stream.eof())
    	{
    		int start = 0, i = 0;
    		vector<string> names;
    		Person person;

    		stream >> buff;

    		while(i < buff.length())
    		{
    			if(buff.at(i) == ',')
    			{  				
    				if(start == 0)
						person.set_name(buff.substr(start,i-start));

    				else
    					names.push_back(buff.substr(start,i-start));

    				start = i + 1;
    			}

    			i++;
    		}

    		names.push_back(buff.substr(start,i-start));

    		// cout << "Name: " << person.get_name() << endl;

    		// for(int i = 0; i < names.size(); i++)
    		// {
    		// 	cout << names.at(i) << endl;
    		// }

    		// cout << "\n";

    		person.set_name_list(names);
    		people.push_back(person);
    	}

    	stream.close();
    }

    else
    {
    	throw "File \"" + string(path) + "\" couldn't be opened.";
    }

	return people;
}

string to_string(Vertex v)
{
	string s = "";

	for(int i = 0; i < v.get_persons().size(); i++)
	{
		s += (string)(v.get_persons().at(i)->get_name());	
		if(i != v.get_persons().size()-1)
			s += " ";
	}

	return s;	
}

string to_string(Person p)
{
	return p.get_name();
}