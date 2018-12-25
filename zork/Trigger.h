#ifndef TRIGGER_H_
#define TRIGGER_H_

#include <stdio.h>
#include <string>
#include <vector>

#include "rapidxml.hpp"

using namespace std;

typedef struct _status {
	string object;
	string status;
}Status;

typedef struct _owner{
	string object;
	string has;
	string owner;
}Owner;

class Trigger {
public:
	Trigger(rapidxml::xml_node <> *);
	virtual ~Trigger() {};

	string type;
	string command;
	string print;
	vector<string> action;
	int numcondition;
	int singletimes;
	bool commandexist;
	bool printexist;
	bool actionexist;

	Status status;
	Owner owner;


private:
	void setuptrigger(rapidxml::xml_node<> *);
	void setupCondition(rapidxml::xml_node<> *, int);
	int countNumCondition(rapidxml::xml_node<> *);
};

#endif