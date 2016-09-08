#include "person.hpp"

using namespace std;

Person::Person()
{
	this->name = "";
	this->name_list = vector<string>();
	this->home = NULL;	//the home vertex for this person
}

Person::Person(vector<string> names)
{
	this->name = "";
	this->name_list = names;
	this->home = NULL;	//the home vertex for this person
}

vector<string> Person::get_name_list() const
{
	return this->name_list;
}

void Person::set_name_list(vector<string> names)
{
	this->name_list = names;
}

string Person::get_name() const
{
	return this->name;
}

void Person::set_name(string name)
{
	this->name = name;
}

Vertex* Person::get_home() const
{
	return this->home;
}

void Person::set_home(Vertex* home)
{
	this->home = home;
}

void Person::operator=(const Person &P)
{
	this->name = P.get_name();
	this->name_list = P.get_name_list();
	this->home = P.get_home();
}