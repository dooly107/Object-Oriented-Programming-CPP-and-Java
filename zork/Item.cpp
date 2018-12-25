#include "Item.h"

Item::Item(rapidxml::xml_node<> * itemnode) {
	setupitem(itemnode);
}

void Item::setupitem(rapidxml::xml_node<> * node) {
	node = node -> first_node();
	string name;
	string value;
	turn = false;

	while(node != NULL) {
		name = node -> name();
		value = node -> value();
		if (name == "name") {
			this -> name = value;
		}
		else if (name == "status") {
			this -> status = value;
		}
		else if (name == "writing") {
			this -> writing = value;
		}
		else if (name == "description") {
			this -> description = value;
		}
		else if (name == "turnon") {
			setupturnon(node);
			turn = true;
		}
		else if (name == "trigger") {
			Trigger* newtrigger = new Trigger(node);
			this -> trigger.push_back(newtrigger);
		}
		node = node -> next_sibling();
	}
}

void Item::setupturnon(rapidxml::xml_node<>* turnonNode) {
	rapidxml::xml_node<> * node = turnonNode -> first_node();
	string name;
	string value;

	while (node != NULL) {
		name = node -> name();
		value = node -> value();
		if (name == "print") {
			this -> turnon.print = value;
		}
		else if (name == "action") {
			this -> turnon.action = value;
		}

		node = node -> next_sibling();
	}
}