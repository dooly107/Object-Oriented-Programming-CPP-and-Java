#ifndef ZORK_H_
#define ZORK_H_

#include "rapidxml.hpp"
#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
#include "Item.h"
#include "Room.h"
#include "Creature.h"
#include "Container.h"
#include <iterator>
#include <sstream>
#include "Trigger.h"
#include <algorithm>
using namespace std;
using namespace rapidxml;

class Zork {
private:
	bool MakeNewWorld(string filename);
	void listxmlintonodes(xml_node<> *, queue<xml_node<> *>&,queue<xml_node<> *>&,queue<xml_node<> *>&,queue<xml_node<> *>&);
	void userCommand(string input);
	bool checkroomtrigger(vector<Trigger *>);
	void changeroom(string input);

public:
	Zork(string);
	bool startgame;

	void start();
	map <string, string> inventory;
	map <string, Item*> items_map;
	map <string, Room*> rooms_map;
	map <string, Creature*> creatures_map;
	map <string, Container*> containers_map;
	map <string, string> object_lookup_map;

	string currentroom;
	string userinput;

	
};

#endif