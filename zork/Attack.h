#ifndef ATTACK_H_
#define ATTACK_H_

#include <stdio.h>
#include "rapidxml.hpp"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef struct _condition {
	string object;
	string status;	
}Condition;

class Attack {
public:
	Attack(rapidxml::xml_node<> *);
	virtual ~Attack() {};

	Condition condition;
	string print;
	vector<string> action;

	bool conditionexist;
	bool printexist;
	bool actionexist;

private:
	void setupattack(rapidxml::xml_node<> *);
	void setupcondition(rapidxml::xml_node<> *);
};

#endif