#include "Node.h"
#include "LinkedList.h"
#include "MyClass.h"
#include <iostream>
#include <string>
using namespace std;

int main(void) {
   LinkedList<int> listInt(5);
   listInt.addNode(9);
   listInt.addNode(2);
   listInt.addNode(1);
   listInt.addNode(11);
   listInt.print( );

   cout << "deleting 5" << endl;
   listInt.deleteNode(5);
   listInt.print( );

   cout << "deleting 1" << endl;
   listInt.deleteNode(1);
   listInt.print( );

   cout << "deleting 11" << endl;
   listInt.deleteNode(11);
   listInt.print( );

   cout << "adding 1" << endl;
   listInt.addNode(1); 
   listInt.print( );

   cout << "adding 11" << endl;
   listInt.addNode(11);
   listInt.print( );

   cout << "adding 5" << endl;
   listInt.addNode(5); 
   listInt.print( );

   LinkedList<MyClass> listMyClass(MyClass(5, 1));
   listMyClass.addNode(MyClass(9, 1));
   listMyClass.addNode(MyClass(2, 2));
   listMyClass.addNode(MyClass(1, 9));
   listMyClass.addNode(MyClass(11, 5));
   listMyClass.print( );

   listMyClass.deleteNode(MyClass(11, -1));
   listMyClass.print( );

   return 0;
}
