#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <string>

using namespace std;

class Person;

class Vertex
{
	public:
		Vertex();
		Vertex(vector<Person*> persons);
		//Vertex(vector<string> names);
		Vertex* deep_copy();
		vector<Person*> get_persons() const;
		void set_persons(vector<Person*> persons);
		Person* get_home() const;
		void set_home(Person* p);

		void operator=(const Vertex &V);

	private:
		vector<Person*> persons;  //starts off with only one person but will become larger as verticies are eliminated};
		Person *home;	//the home person for this vertex
 };

#endif