#ifndef CONTAINER_H_
#define CONTAINER_H_

#include <stdio.h>
#include "rapidxml.hpp"
#include "Trigger.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Container {
public:
	Container(rapidxml::xml_node<> *);
	virtual ~Container() {};

	string name;
	string status;
	string description;
	vector <string> accept;
	vector <string> item;
	vector <Trigger *> trigger;
	

private:
	void setupcontainer(rapidxml::xml_node<> *);
};

#endif