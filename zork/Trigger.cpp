#include "Trigger.h"
#include "Zork.h"

Trigger::Trigger(rapidxml::xml_node<> * node) {
	setuptrigger(node -> first_node());
}

void Trigger::setuptrigger(rapidxml::xml_node<>* triggernode) {
	string name;
	string value;
	numcondition = 0;
	singletimes = 0;
	type = "single";
	this -> commandexist = false;
	this -> printexist = false;
	this -> actionexist = false;

	while (triggernode != NULL) {
		name = triggernode -> name();
		value = triggernode -> value();
		if (name == "type") {
			this -> type = value;
		}
		else if (name == "command") {
			this -> command = value;
			this -> commandexist = true;
		}
		else if (name == "print") {
			this -> print = value;
			this -> printexist = true;
		}
		else if (name == "action") {
			this -> action.push_back(value);
			this -> actionexist = true;
		}
		else if (name == "condition") {
			numcondition = countNumCondition(triggernode);
			setupCondition(triggernode, numcondition);
		}
		triggernode = triggernode -> next_sibling();
	}
}

int Trigger::countNumCondition(rapidxml::xml_node<> * conditionnode) {
	int num = 0;
	rapidxml::xml_node<> * countnode = conditionnode -> first_node();
	while (countnode != NULL) {
		num++;
		countnode = countnode -> next_sibling();
	}
	return num;
}

void Trigger::setupCondition(rapidxml::xml_node<>* conditionnode, int numcondition) {
	rapidxml::xml_node<> * child_conditionnode = conditionnode -> first_node();
	string name;
	string value;

	if (numcondition == 3) {
		while (child_conditionnode != NULL) {
			name = child_conditionnode -> name();
			value = child_conditionnode -> value();
			if (name == "has") {
				this -> owner.has = value;
			}
			else if (name == "object") {
				this -> owner.object = value;
			}
			else if (name == "owner") {
				this -> owner.owner = value;
			}
			child_conditionnode = child_conditionnode -> next_sibling();
		}
	}
	else if (numcondition == 2) {
		while (child_conditionnode != NULL) {
			name = child_conditionnode -> name();
			value = child_conditionnode -> value();
			if (name == "object") {
				this -> status.object = value;
			}
			else if (name == "status") {
				this -> status.status = value;
			}
			child_conditionnode = child_conditionnode -> next_sibling();
		}
	}
}


