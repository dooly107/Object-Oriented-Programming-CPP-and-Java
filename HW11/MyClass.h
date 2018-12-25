#ifndef MYCLASS_H_
#define MYCLASS_H_
#include <iostream>
#include <string>
using namespace std;

class MyClass {
   int key;
   int data;
public:
   MyClass(int key, int data);
   MyClass( );
   virtual ~MyClass( );
   bool operator<(const MyClass& rhs) const;
   bool operator==(const MyClass& rhs) const;
   friend ostream& operator<<(ostream& ostr, const MyClass m);
};

#endif /* MYCLASS_H_ */
