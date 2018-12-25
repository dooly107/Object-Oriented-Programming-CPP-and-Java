#include "Trigger.h"
#include "Zork.h"

Trigger::~Trigger() {}

Trigger::Trigger(rapidxml::xml_node<> * node) {
	setuptrigger(node -> first_node());
}

bool Trigger::check(Zork& zork) {
	for (std::vector<Condition *>::iterator trig_condition = conditions.begin(); trig_condition != conditions.end(); trig_condition++) {
		if (!(*trig_condition)->check(zork)) {
			return false;
		}
	}
	return true;
}

void Trigger::setuptrigger(rapidxml::xml_node<>* triggernode) {
	string name;
	string value;
	
	while (triggernode != NULL) {
		name = triggernode -> name();
		value = triggernode -> value();
		if (name == "type") {
			this -> type = value;
		}
		else if (name == "command") {
			this -> conditions.push_back(new Command(triggernode));
			this->commandexist = true;
		}
		else if (name == "condition") {
			setupCondition(triggernode);
		}
		else if (name == "print") {
			this -> print.push_back(value);
		}
		else if (name == "action") {
			this -> action.push_back(value);
		}
		triggernode = triggernode -> next_sibling();
	}
}

void Trigger::setupCondition(rapidxml::xml_node<>* conditionnode) {
	rapidxml::xml_node<> * child_conditionnode = conditionnode -> first_node();
	string name;

	while (child_conditionnode != NULL) {
		name = child_conditionnode -> name();
		if (name == "has") {
			this -> conditions.push_back(new ConditionHas(child_conditionnode));
		}
		if (name == "status") {
			this -> conditions.push_back(new ConditionStatus(child_conditionnode));
		}
		child_conditionnode = child_conditionnode -> next_sibling();
	}
}