#include "MyClass.h"

MyClass::MyClass(int key, int data) : key(key), data(data) { }

MyClass::MyClass( ) : key(0), data(-1) { }

MyClass::~MyClass( ) { }

bool MyClass::operator<(const MyClass& rhs) const {
   return key < rhs.key;
}

bool MyClass::operator==(const MyClass& rhs) const {
   return key == rhs.key;
}

ostream& operator<< (ostream& os, const MyClass m) {
   os << "<" << m.key << ", " << m.data << "> ";
   return os;
}
