#include "ConditionHas.h"
#include "Zork.h"

ConditionHas::ConditionHas(rapidxml::xml_node <>* conditionhasnode) {
	setupconditionhas(conditionhasnode -> first_node());
}

ConditionHas::~ConditionHas() {}

void ConditionHas::setupconditionhas(rapidxml::xml_node <>* conditionhasnode) {
	string name;
	string value;
	while (conditionhasnode != NULL) {
		name = conditionhasnode -> name();
		value = conditionhasnode -> value();
		if (name == "has") {
			this -> has = value;
		}
		else if (name == "object") {
			this -> object = value;
		}
		else if (name == "owner") {
			this -> owner = value;
		}
		conditionhasnode = conditionhasnode -> next_sibling();
	}
}

bool ConditionHas::check(Zork& zork) {
	bool isinventory;
	bool isroom;
	bool iscontainer;

	isinventory = (owner == "inventory");
	isroom = (zork.rooms_map.find(owner) != zork.rooms_map.end());
	iscontainer = (zork.containers_map.find(owner) != zork.containers_map.end());

	if (isinventory) {
		if (zork.inventory.find(object) != zork.inventory.end()) {
			if (has == "yes" || has == "no") {
				return true;
			}
			else {
				return false;
			}
		}
	}
	else if (isroom) {
		Room * roomcheck = zork.rooms_map.find(owner) -> second;
		bool roomhasitem = (roomcheck -> items.find(object) != roomcheck -> items.end());
		bool hasiteminroom = (has == "yes");
		if ((hasiteminroom && roomhasitem) || (!hasiteminroom && !roomhasitem)) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (iscontainer) {
		Container * containercheck = zork.containers_map.find(owner) -> second;
		bool containerhasitem = (containercheck -> item.find(object) != containercheck -> item.end());
		bool hasitemincontainer = (has == "yes");
		if ((hasitemincontainer && containerhasitem) || (!hasitemincontainer && !containerhasitem)) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

