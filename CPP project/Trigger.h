#ifndef TRIGGER_H_
#define TRIGGER_H_

#include <stdio.h>
#include <string>
#include <vector>

#include "ConditionStatus.h"
#include "ConditionHas.h"
#include "rapidxml.hpp"
#include "Command.h"
#include "Condition.h"

using namespace std;

class Trigger {
public:
	Trigger(rapidxml::xml_node <> *);
	~Trigger();

	vector<Condition *> conditions;
	vector<string> print;
	vector<string> action;
	string type;
	bool commandexist;
	bool check(Zork&);

private:
	void setuptrigger(rapidxml::xml_node<> *);
	void setupCondition(rapidxml::xml_node<> *);
};

#endif