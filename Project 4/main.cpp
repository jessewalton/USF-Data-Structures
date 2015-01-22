/*******************************************************************************
Project 4                                                           Jesse Walton
main.cpp                                                            U89823440
*******************************************************************************/

#include "functions.h"
#include <string>
#include <iostream>

using namespace std;

// function prototypes
void testInfixFunction();
void testRadixSort();

int main() {

   testRadixSort();
   testInfixFunction();

   return 0;
}


void testRadixSort() {

   int digitLength = 2;
   int base = 16;

   vector<string> numbers;
   vector<string>::iterator newIt;

   numbers.push_back("F0");
   numbers.push_back("E1");
   numbers.push_back("D2");
   numbers.push_back("C3");
   numbers.push_back("B4");
   numbers.push_back("A5");
   numbers.push_back("96");
   numbers.push_back("87");
   numbers.push_back("78");
   numbers.push_back("69");
   numbers.push_back("5A");
   numbers.push_back("4B");
   numbers.push_back("3C");
   numbers.push_back("2D");
   numbers.push_back("1E");
   numbers.push_back("0F");

   radixSort(numbers, digitLength, base);

   // print out sorted values
   cout << "Sorted Values: " << endl;
   for (newIt = numbers.begin(); newIt != numbers.end(); newIt++) {
      cout << *newIt << endl;
   }
   cout << endl;

}

void testInfixFunction() {
   string postfixExpression = "abc-+de-fg-h+/*";
   string infixExpression;

   infixExpression = getInfixExpression(postfixExpression);

   cout << "Postfix Expression: " << postfixExpression << endl;
   cout << "Infix Expression: " << infixExpression << endl;
}

