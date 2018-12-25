#ifndef ITEM_H_
#define ITEM_H_

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include "rapidxml.hpp"
#include "Trigger.h"

using namespace std;

typedef struct _turnon {
	string print;
	string action;
}Turnon;

class Item {

public:
	Item (rapidxml::xml_node<> *);
	virtual ~Item() {};
	string name;
	string status;
	string description;
	string writing;
	Turnon turnon;
	vector<Trigger *> trigger;

	bool turn;

private:
	void setupitem(rapidxml::xml_node<> *);
	void setupturnon(rapidxml::xml_node<> *);
};

#endif
