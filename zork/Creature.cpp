#include "Creature.h"

Creature::Creature(rapidxml::xml_node<> * node) {
	setupcreature(node -> first_node());
}

void Creature::setupcreature(rapidxml::xml_node<> * creaturenode) {
	string name;
	string value;
	attackexist = false;

	while (creaturenode != NULL) {
		name = creaturenode -> name();
		value = creaturenode -> value();
		if (name == "name") {
			this -> name = value;
		}
		else if (name == "status") {
			this -> status = value;
		}
		else if (name == "vulnerability") {
			this -> vulnerability.push_back(value);
		}
		else if (name == "attack") {
			this -> attackexist = true;
			this -> attack = new Attack(creaturenode);
		}
		else if (name == "trigger") {
			Trigger* newtrigger = new Trigger(creaturenode);
			this -> trigger.push_back(newtrigger);
		}
		creaturenode = creaturenode -> next_sibling();
	}
}


