#ifndef CREATURE_H_
#define CREATURE_H_

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include "rapidxml.hpp"
#include "Trigger.h"

using namespace std;

class Creature {
private:
	void setupcreature(rapidxml::xml_node<> *);
	void setupattack(rapidxml::xml_node<> *);
	void setupconditions(rapidxml::xml_node<> *);
public:
	Creature(rapidxml::xml_node<> *);
	virtual ~Creature();
	bool attackcreature(Zork&, string);
	string name;
	string description;
	string status;
	map<string, string> vulnerability;
	vector <string> print;
	vector <string> action;
	vector <Trigger *> trigger;
	vector <Condition *> condition;
};

#endif