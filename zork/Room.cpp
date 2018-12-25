#include "Room.h"

Room::Room(rapidxml::xml_node<> * roomnode) {
	setuproom(roomnode -> first_node());
}

void Room::setuproom(rapidxml::xml_node<> * curroomnode) {
	string name;
	string value;
	while (curroomnode != NULL) {
		name = curroomnode -> name();
		value = curroomnode -> value();
		if (name == "name") {
			this -> name = value;
		}
		else if (name == "status") {
			this -> status = value;
		}
		else if (name == "type") {
			this -> type = value;
		}
		else if (name == "description") {
			this -> description = value;
		}
		else if (name == "border") {
			setupborder(curroomnode);
		}
		else if (name == "container") {
			this -> container.push_back(value);
		}
		else if (name == "item") {
			this -> item.push_back(value);
		}
		else if (name == "creature") {
			this -> creature.push_back(value);
		}
		else if (name == "trigger") {
			Trigger * newtrigger = new Trigger(curroomnode);
			this -> trigger.push_back(newtrigger);
		}
		curroomnode = curroomnode -> next_sibling();
	}
}


void Room::setupborder(rapidxml::xml_node<> * bordernode) {
	rapidxml::xml_node<> * borderchild = bordernode -> first_node();
	Border* newborder = new Border();
	string name;
	string value;
	string dir;

	while (borderchild != NULL) {
		name = borderchild -> name();
		value = borderchild -> value();
		if (name == "direction") {
			if (value == "north") {
				dir = "n";
			}
			else if (value == "south") {
				dir = "s";
			}
			else if (value == "east") {
				dir = "e";
			}
			else if (value == "west") {
				dir = "w";
			}
			newborder -> direction = dir;
		}
		else if (name == "name") {
			newborder -> name = value;
		}
		borderchild = borderchild -> next_sibling();
	}
	this -> border.push_back(newborder);
}
