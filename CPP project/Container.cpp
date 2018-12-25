#include "Container.h"

Container::Container(rapidxml::xml_node<> * containernode) {
	setupcontainer(containernode -> first_node());
}

Container::~Container() {}


void Container::setupcontainer(rapidxml::xml_node<> * containernode) {
	string name;
	string value;

	while (containernode != NULL) {
		name = containernode -> name();
		value = containernode -> value();
		if (name == "name") {
			this -> name = value;
		}
		else if (name == "status") {
			this -> status = value;
		}
		else if (name == "description") {
			this -> description = value;
		}
		else if (name == "accept") {
			this -> accept.push_back(value);
		}
		else if (name == "item") {
			this -> item[value] = value;
		}
		else if (name == "trigger") {
			this -> trigger.push_back(new Trigger(containernode));
		}

		containernode = containernode -> next_sibling();
	}
}