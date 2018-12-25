#include "Item.h"

Item::Item() { }

Item::Item(const Item& orig) {
	this -> name = orig.name;
	this -> description = orig.description;
	this -> status = orig.status;
	this -> writing = orig.writing;
	this -> turnonMessage = orig.turnonMessage;
	this -> turnonAction = orig.turnonAction;
}

Item::~Item() { }

Item::Item(rapidxml::xml_node<> * itemnode) {
	setupitem(itemnode);
}

void Item::setupitem(rapidxml::xml_node<> * node) {
	node = node -> first_node();
	string header;
	string value;

	while(node != NULL) {
		header = node -> name();
		value = node -> value();

		if (header == "name") {
			this -> name = (value);
		}
		else if (header == "writing") {
			this -> writing = (value);
		}
		else if (header == "status") {
			this -> status = (value);
		}
		else if (header == "turnon") {
			setupturnon(node -> first_node());
		}
		node = node -> next_sibling();
	}
}

void Item::setupturnon(rapidxml::xml_node<>* turnonNode) {
	string header;
	string value;

	while (turnonNode != NULL) {
		header = turnonNode -> name();
		value = turnonNode -> value();
		if (header == "print") {
			this -> turnonMessage.push_back(value);
		}
		else if (header == "action") {
			this -> turnonAction.push_back(value);
		}

		turnonNode = turnonNode -> next_sibling();
	}
}