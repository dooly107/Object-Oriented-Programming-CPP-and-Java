#include "Room.h"

Room::Room(rapidxml::xml_node<> * roomnode) {
	setuproom(roomnode -> first_node());
}

Room::~Room() {}

void Room::setuproom(rapidxml::xml_node<> * curroomnode) {
	string name;
	string value;
	while (curroomnode != NULL) {
		name = curroomnode -> name();
		value = curroomnode -> value();
		if (name == "name") {
			this -> name = value;
		}
		else if (name == "description") {
			this -> description = value;
		}
		else if (name == "item") {
			this -> items[value] = value;
		}
		else if (name == "trigger") {
			this -> triggers.push_back(new Trigger(curroomnode));
		}
		else if (name == "creature") {
			this -> creatures[value] = value;
		}
		else if (name == "container") {
			this -> containers[value] = value;
		}
		else if (name == "type") {
			this -> type = type;
		}
		else if (name == "border") {
			setupborder(curroomnode);
		}
		curroomnode = curroomnode -> next_sibling();
	}
}


void Room::setupborder(rapidxml::xml_node<> * bordernode) {
	rapidxml::xml_node<> * borderchild = bordernode -> first_node();
	string name;
	string value;
	string direction;
	string roomname;
	while (borderchild != NULL) {
		name = borderchild -> name();
		value = borderchild -> value();
		if (name == "direction") {
			direction = value;
		}
		else if (name == "name") {
			roomname = value;
		}
		borderchild = borderchild -> next_sibling();
	}
	this -> borders[direction] = roomname;
}
