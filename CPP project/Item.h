#ifndef ITEM_H_
#define ITEM_H_

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include "rapidxml.hpp"

using namespace std;

class Item {
public:
	Item(rapidxml::xml_node<> *);
	Item(const Item&);
	Item();
	virtual ~Item();

	string name;
	string status;
	string description;
	string writing;
	vector<string> turnonMessage;
	vector<string> turnonAction;

private:
	void setupitem(rapidxml::xml_node<> *);
	void setupturnon(rapidxml::xml_node<> *);
};

#endif
