#ifndef CONDITION_H_
#define CONDITION_H_

#include <stdio.h>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Zork;

class Condition {
public:
	string object;
	virtual bool check(Zork&);
	virtual ~Condition() {};
};

#endif