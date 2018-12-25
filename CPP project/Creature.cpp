#include "Creature.h"

Creature::Creature(rapidxml::xml_node<> * node) {
	setupcreature(node);
}

Creature::~Creature() {};

bool Creature::attackcreature(Zork& zork, string weapon) {
	if (vulnerability.find(weapon) == vulnerability.end()) {
		return false;
	}
	else {
		return true;
	}
}

void Creature::setupcreature(rapidxml::xml_node<> * creaturenode) {
	string name;
	string value;

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
			this -> vulnerability[name] = value;
		}
		else if (name == "attack") {
			setupattack(creaturenode);
		}
		else if (name == "trigger") {
			this -> trigger.push_back(new Trigger(creaturenode));
		}
		creaturenode = creaturenode -> next_sibling();
	}
}


void Creature::setupattack(rapidxml::xml_node<> * attacknode) {
	rapidxml::xml_node<> * attackchildnode = attacknode -> first_node();
	string name;
	string value;
	while (attackchildnode != NULL) {
		name = attackchildnode -> name();
		value = attackchildnode -> value();
		if (name == "condition") {
			setupconditions(attackchildnode);
		}
		else if (name == "print") {
			this -> print.push_back(value);
		}
		else if (name == "action") {
			this -> action.push_back(value);
		}
		attackchildnode = attackchildnode -> next_sibling();
	}
}


void Creature::setupconditions(rapidxml::xml_node<> * conditionnode) {
	rapidxml::xml_node<> * conditionchildnode = conditionnode -> first_node();
	string name;
	string value;
	while (conditionchildnode != NULL) {
		name = conditionchildnode -> name();
		value = conditionchildnode -> value();
		if (name == "has") {
			this -> condition.push_back(new ConditionHas(conditionnode));
		}
		if (name == "status") {
			this -> condition.push_back(new ConditionStatus(conditionnode));
		}
		conditionchildnode = conditionchildnode -> next_sibling();
	}
}

