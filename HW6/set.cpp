#include <string>
#include <iostream>

#include "set.h"
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

Set	Set::operator + (int const value) {
	Set temp;
	temp.setbit = setbit;
	temp.count = count;
	temp.values = new int[setbit + 2]( );
	temp.values[value] = 1;
	for (int i = 0; i <= setbit + 1; i++)
		if (values[i] != temp.values[i])
			temp.values[i] = 1;
	return temp;
}

Set Set::operator / (const Set& setref) {
	Set temp;
	temp.setbit = setbit;
	temp.count = setref.count + 1;
	temp.values = new int[setbit + 2]( );
	for (int l = 0; l <= setbit + 1; l++)
		if (values[l] == 1)
			if (values[l] != setref.values[l])
				temp.values[l] = 1;
	return temp;
}

Set Set::operator - (int const value) {
	Set temp;
	temp.setbit = setbit;
	temp.count = count;
	temp.values = new int[setbit + 2]( );
	temp.values[value] = 1;
	for (int i = 0; i <= setbit + 1; i++)
		if (temp.values[i] == values[i])
			temp.values[i] = 0;
		else
			temp.values[i] = values[i];
	return temp;
}

Set Set::operator ~ () {
	Set temp;
	temp.setbit = setbit;
	temp.count = count + 1;
	temp.values = new int[setbit + 2]( );
	for (int j = 0; j <= setbit + 1; j++)
		temp.values[j] = 1;
	for (int i = 0; i <= setbit + 1; i++)
		if (values[i] == 1)
			temp.values[i] = 0;
	return temp;
}

Set Set::operator & (const Set& setref) {
	Set temp;
	temp.setbit = setbit + 1;
	temp.count = setref.count;
	temp.values = new int[setbit + 2]( );
	for (int i = 0; i <= setbit + 1; i++)
		if (values[i] == 1 && setref.values[i] == 1)
			temp.values[i] = 1;
	return temp;
}

Set	Set::operator = (const Set& setref) {
	count = setref.count + 1;
	for (int i = 0; i <= setbit + 1; i++)
		values[i] = 0;
	for (int j = 0; j <= setbit + 1; j++)
		if (setref.values[j] == 1)
			values[j] = 1;
	return *this;
}

std::ostream& operator << (std::ostream& out, const Set& set) {
	int setbit = set.setbit;
	for (int k = 0; k <= setbit; k++)
		if (set.values[k] == 1)
			out << k << " ";
	return out;
}


Set::~Set( ) { }
