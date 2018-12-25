#ifndef CONDITIONHAS_H_
#define CONDITIONHAS_H_

#include <stdio.h>
#include <string>
#include <vector>
#include "rapidxml.hpp"
#include "Condition.h"

using namespace std;

class ConditionHas : public Condition {
public:
	ConditionHas(rapidxml::xml_node<> *);
	~ConditionHas();
	bool check(Zork &);

	string has;
	string owner;

private:
	void setupconditionhas(rapidxml::xml_node<> *);
};

#endif