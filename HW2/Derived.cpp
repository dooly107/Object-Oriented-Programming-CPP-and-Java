#include "Derived.h"
#include <iostream>

Derived::Derived( ) { }
Derived::~Derived( ) { }

// add necessary functions here
void Derived::f1(  ) {
   std::cout << "Base f1" << std::endl;
}

void Derived::f2(  ) {
   std::cout << "Derived f2" << std::endl;
}
