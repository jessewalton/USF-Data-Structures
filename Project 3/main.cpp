
// Jesse Walton
// main.cpp

#include "circularLinkedList.h"
#include <iostream>
#include <ctime>

int main() {

   srand(time(NULL));

   List<int> testList;

   if(testList.isEmpty())
      cout << "The list is empty" << endl;
   else
      cout << "The list is not empty" << endl;


   testList.insert(0,0);
   testList.display(cout);
   cout << endl;

   testList.insert(10,0);
   testList.display(cout);
   cout << endl;

   testList.insert(20,0);
   testList.display(cout);
   cout << endl;

   testList.insert(30,2);
   testList.display(cout);
   cout << endl;

   testList.insert(40,3);
   testList.display(cout);
   cout << endl;

   testList.insert(50,4);
   testList.display(cout);
   cout << endl;

   testList.insert(50,25);
   testList.display(cout);
   cout << endl;

   cout << "getSize(): " << testList.getSize() << endl;

   List<int> newList = testList; // test copy constructor

   List <int>newerList;
   newerList = testList; // test assignment operator


   cout << "Display newList: " << endl;
   newList.display(cout);
   cout << endl;

   newList.runJosephusAlgorithm();

   cout << "Display newList: " << endl;
   newList.display(cout);
   cout << endl;

}
