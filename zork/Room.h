#ifndef ROOM_H_
#define ROOM_H_

#include <stdio.h>
#include <string>
#include <vector>
#include "rapidxml.hpp"
#include "Trigger.h"

using namespace std;

typedef struct _border {
	string direction;
	string name;
}Border;

class Room {
public:
	Room(rapidxml::xml_node<> *);
	virtual ~Room() {};

	string name;
	string description;
	string type;
	string status;
	vector<Border *> border;
	vector<Trigger *> trigger;
	vector<string> container;
	vector<string> creature;
	vector<string> item;

private:
	void setuproom(rapidxml::xml_node<> *);
	void setupborder(rapidxml::xml_node<> *);
};

#endif