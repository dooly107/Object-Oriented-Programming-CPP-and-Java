#ifndef CREATURE_H_
#define CREATURE_H_

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include "rapidxml.hpp"
#include "Trigger.h"
#include "Attack.h"

using namespace std;

class Creature {
private:
	void setupcreature(rapidxml::xml_node<> *);
public:
	Creature(rapidxml::xml_node<> *);
	virtual ~Creature() {};
	bool attackexist;
	string name;
	string status;
	string description;
	vector<string> vulnerability;
	Attack* attack;
	vector<Trigger *> trigger;
};

#endif