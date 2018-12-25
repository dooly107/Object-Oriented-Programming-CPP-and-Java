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
	bool checktrigger_wocommand();
	bool checktrigger_wcommand(string);
	string findtype(string);
	bool ownertrigger(Trigger *);
	bool statustrigger(Trigger *);
	void performaction(string);
	void inputcommand(string);
	void changeroom(string);
	void listinventory();
	void taketoinventory(string);
	void opencontainer(string);
	void openexit();
	void readitem(string);
	void dropitem(string);
	void putitemincontainer(string);
	void turnonitem(string);
	void attackcreature(string);

	void Add(string);
	void Update(string);
	void Delete(string);
	void GameOver();

public:
	Zork(string);
	bool startgame;
	bool finishgame;

	void start();
	Room* currentroom;
	vector <string> inventory;
	vector <Item *> itemlist;
	vector <Room *> roomlist;
	vector <Creature *> creaturelist;
	vector <Container *> containerlist;

	string currentroomname;
	string userinput;

	bool opencontainertrue;
};

#endif