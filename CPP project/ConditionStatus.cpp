#include "ConditionStatus.h"
#include "Zork.h"

ConditionStatus::ConditionStatus(rapidxml::xml_node<> * conditionstatusnode) {
	setupconditionstatus(conditionstatusnode -> first_node());
}

void ConditionStatus::setupconditionstatus(rapidxml::xml_node<> * conditionstatusnode) {
	string name;
	string value;
	while (conditionstatusnode != NULL) {
		name = conditionstatusnode -> name();
		value = conditionstatusnode -> value();
		if (name == "object") {
			this -> object = value;
		}
		else if (name == "status") {
			this -> status = value;
		}

		conditionstatusnode = conditionstatusnode -> next_sibling();
	}
}

ConditionStatus::~ConditionStatus() {}

bool ConditionStatus::check(Zork& zork) {
	return true;
}