#ifndef ROOM_H_
#define ROOM_H_

#include <stdio.h>
#include <string>
#include <vector>
#include "rapidxml.hpp"
#include "Trigger.h"

using namespace std;

class Room {
public:
	Room(rapidxml::xml_node<> *);
	virtual ~Room();

	string name;
	string description;
	string type;
	map <string, string> borders;
	map <string, string> containers;
	map <string, string> items;
	map <string, string> creatures;
	vector <Trigger *> triggers;

private:
	void setuproom(rapidxml::xml_node<> *);
	void setupborder(rapidxml::xml_node<> *);
};

#endif