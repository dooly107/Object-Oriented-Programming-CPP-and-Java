#ifndef SET_NONMEMBER_H_
#define SET_NONMEMBER_H_
#include <string>
#include <iostream>

class Set {
	public:
		Set();
		Set(int setbits);
		int getCopyCount( );
		friend Set operator + (const Set& setorig, const int value);
		friend Set operator - (const Set& setorig, const int value);
		friend Set operator & (const Set& setorig, const Set& setref);
		friend Set operator ~ (const Set& setorig);
		friend Set operator / (const Set& setorig, const Set& setref);
		friend std::ostream& operator << (std::ostream& out, const Set& set);
		virtual ~Set( );
	private:
		int setbit;
		int* values;
		int count;
};
Set operator + (const Set& setorig, const int value);
Set operator - (const Set& setorig, const int value);
Set operator & (const Set& setorig, const Set& setref);
Set operator ~ (const Set& setorig);
Set operator / (const Set& setorig, const Set& setref);
std::ostream& operator << (std::ostream& out, const Set& set);

#endif /* SET_H_ */
