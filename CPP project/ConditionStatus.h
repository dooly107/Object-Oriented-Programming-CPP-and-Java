#ifndef CONDITIONSTATUS_H_
#define CONDITIONSTATUS_H_

#include <stdio.h>
#include <map>
#include <string>
#include <vector>
#include "rapidxml.hpp"
#include "Condition.h"

using namespace std;

class ConditionStatus : public Condition {
public:
	string status;
	ConditionStatus(rapidxml::xml_node<> *);
	~ConditionStatus();
	bool check(Zork&);
private:
	void setupconditionstatus(rapidxml::xml_node<> *);
};

#endif