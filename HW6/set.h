#ifndef SET_H_
#define SET_H_
#include <string>
#include <iostream>

class Set {
	public:
		Set();
		Set(int setbits);
		int getCopyCount( );
		Set operator + (const int value);
		Set operator - (const int value);
		Set operator = (const Set& setref);
		Set operator & (const Set& setref);
		Set operator ~ ();
		Set operator / (const Set& setref);
		friend std::ostream& operator << (std::ostream& out, const Set& set);
		virtual ~Set( );
	private:
		int setbit;
		int* values;
		int count;
};

std::ostream& operator << (std::ostream& out, const Set& set);

#endif /* SET_H_ */
