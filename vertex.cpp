#include "vertex.hpp"
#include "person.hpp"

using namespace std;

Vertex::Vertex()
{
	this->persons = vector<Person*>();
	this->home = NULL;
}

Vertex::Vertex(vector<Person*> persons)
{
	this->persons = persons;
	this->home = NULL;
}

// Vertex::Vertex(vector<string> names)
// {	
// 	vector<Person*> persons = vector<Person*>();

// 	for(int i = 0; i < names.size(); i++)
// 	{
// 		persons.push_back(new Person(names.at(i)));
// 	}

// 	this->persons = persons;
// 	this->home = NULL;
// }

Vertex* Vertex::deep_copy()
{
	Vertex* v = new Vertex(this->persons);
	v->set_home(this->home);
	return v;
}

vector<Person*> Vertex::get_persons() const
{
	return this->persons;
}

void Vertex::set_persons(vector<Person*> persons)
{
	this->persons = persons;
}

Person* Vertex::get_home() const
{
	return home;
}

void Vertex::set_home(Person* p)
{
	this->home = p;
}

void Vertex::operator=(const Vertex &V)
{
	this->persons = V.get_persons();
	this->home = V.get_home();
}