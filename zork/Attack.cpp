#include "Attack.h"

Attack::Attack(rapidxml::xml_node<> * attacknode) {
	setupattack(attacknode -> first_node());
}

void Attack::setupattack(rapidxml::xml_node<> * node) {
	string name;
	string value;
	this -> conditionexist = false;
	this -> printexist = false;
	this -> actionexist = false;

	while(node != NULL) {
		name = node -> name();
		value = node -> value();
		if (name == "condition") {
			this -> conditionexist = true;
			setupcondition(node);
		}
		else if(name == "print") {
			this -> print = value;
			this -> printexist = true;
		}
		else if (name == "action") {
			this -> action.push_back(value);
			this -> actionexist = true;
		}
		node = node -> next_sibling();
	}
}

void Attack::setupcondition(rapidxml::xml_node<> * conditionnode) {
	rapidxml::xml_node<> * node = conditionnode -> first_node();
	string name;
	string value;

	while (node != NULL) {
		name = node -> name();
		value = node -> value();
		if (name == "object") {
			this -> condition.object = value;
		}
		else if (name == "status") {
			this -> condition.status = value;
		}
		node = node -> next_sibling();
	}
}