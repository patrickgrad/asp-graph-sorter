#ifndef PERSON_H
#define PERSON_H

#include <vector>
#include <string>

using namespace std;

class Vertex;

class Person
{
	public:
		Person();
		Person(vector<string> names);
		vector<string> get_name_list() const;
		void set_name_list(vector<string> names);
		string get_name() const;
		void set_name(string name);
		Vertex* get_home() const;
		void set_home(Vertex* v);

		void operator=(const Person &p);

	private:
		string name;
		vector<string> name_list;
		Vertex *home;	//the home vertex for this person
};

#endif
