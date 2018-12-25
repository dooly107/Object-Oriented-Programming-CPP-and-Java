#include <string>
#include <iostream>

#include "set_nonmember.h"
using namespace std;

Set::Set( ) { }

int Set::getCopyCount ( ) {
	return count;
}

Set::Set(int setint) {
	setbit = setint;
	values = new int[setbit + 2]( );
	count = 0;
}

Set operator + (const Set& setorig, int const value) {
	Set temp;
	temp.setbit = setorig.setbit;
	temp.count = setorig.count + 1;
	temp.values = new int[setorig.setbit + 2]( );
	temp.values[value] = 1;
	for (int i = 0; i <= setorig.setbit + 1; i++)
		if (setorig.values[i] != temp.values[i])
			temp.values[i] = 1;
	return temp;
}

Set operator / (const Set& setorig, const Set& setref) {
	Set temp;
	temp.setbit = setorig.setbit;
	temp.count = setref.count + 1;
	temp.values = new int[setorig.setbit + 2]( );
	for (int l = 0; l <= setorig.setbit + 1; l++)
		if (setorig.values[l] == 1)
			if (setorig.values[l] != setref.values[l])
				temp.values[l] = 1;
	return temp;
}

Set operator - (const Set& setorig, int const value) {
	Set temp;
	temp.setbit = setorig.setbit;
	temp.count = setorig.count + 1;
	temp.values = new int[setorig.setbit + 2]( );
	temp.values[value] = 1;
	for (int i = 0; i <= setorig.setbit + 1; i++)
		if (temp.values[i] == setorig.values[i])
			temp.values[i] = 0;
		else
			temp.values[i] = setorig.values[i];
	return temp;
}

Set operator ~ (const Set& setorig) {
	Set temp;
	temp.setbit = setorig.setbit;
	temp.count = setorig.count + 1;
	temp.values = new int[setorig.setbit + 2]( );
	for (int j = 0; j <= setorig.setbit + 1; j++)
		temp.values[j] = 1;
	for (int i = 0; i <= setorig.setbit + 1; i++)
		if (setorig.values[i] == 1)
			temp.values[i] = 0;
	return temp;
}

Set operator & (const Set& setorig, const Set& setref) {
	Set temp;
	temp.setbit = setorig.setbit;
	temp.count = setref.count + 1;
	temp.values = new int[setorig.setbit + 2]( );
	for (int i = 0; i <= setorig.setbit + 1; i++)
		if (setorig.values[i] == 1 && setref.values[i] == 1)
			temp.values[i] = 1;
	return temp;
}

std::ostream& operator << (std::ostream& out, const Set& set) {
	int setbit = set.setbit;
	for (int k = 0; k <= setbit; k++)
		if (set.values[k] == 1)
			out << k << " ";
	return out;
}


Set::~Set( ) { }
