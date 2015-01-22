/*******************************************************************************
Project 4                                                           Jesse Walton
functions.h                                                         U89823440
*******************************************************************************/

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <string>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

string getInfixExpression(const string& input)
/*******************************************************************************
getInfixExpression(String of values)
   Description: Reorder string containing postfix notation into infix notation.
   Precondition: Input string of postfix expression
   Postcondition: Return string of infix expression
*******************************************************************************/
{
   stack<string> aStack;

   int element = 0;

   // loop until all charters are cycled through
   while (input[element] != '\0') {

      int startLetter = 'a';
      int endLetter = 'z';
      int currentValue = input[element];

      // test for operand
      if (currentValue >= startLetter && currentValue <= endLetter) {
         aStack.push(input.substr(element,1));
      }

      // test for operator
      else if (currentValue == '+' || currentValue == '-'
         || currentValue == '*' || currentValue == '/') {

         // save top of stack to be end of new operand
         string newOperandEnd = aStack.top();
         aStack.pop();

         // save operator to be middle of new operand
         string newOperandMiddle = input.substr(element,1);

         // save top of stack to be beginning of new operand
         string newOperandFront = aStack.top();
         aStack.pop();

         // create new operand
         string newOperand;

         // construct new operand
         newOperand += "(";
         newOperand += newOperandFront;
         newOperand += newOperandMiddle;
         newOperand += newOperandEnd;
         newOperand += ")";

         // push new operand onto stack
         aStack.push(newOperand);
      }

      // otherwise, element is invalid
      else {
         // do nothing
      }

      element++;
   }
   return aStack.top();
}

void radixSort(vector<string>& numbers,
   const int& digitsPerNumber,
   const int& radix)
/*******************************************************************************
radixSort(vector of strings, # of elements in largest number, base of numbers)
   Description: Reorder values into ascending order using a radix sort.
   Precondition: Input vector containing string values, base of values and
      number of digits in largest number.
   Postcondition: String values in vector will be sorted in ascending order.
*******************************************************************************/
{
   /* Create a queue for each possible number that can be in a number */
   vector< queue<string> > buckets(radix);

   // Iterator
   vector<string>::iterator it;

   int bucket;
   int divisor = radix;
   int power = 0;
   int number = 0;


   /* Iterate over the digits of each number, starting with least signifigant */
   for(int digit = 0; digit < digitsPerNumber; digit++) {

      /* Iterate over each number in the vector and put in bucket */
      for(it = numbers.begin(); it !=  numbers.end(); it++) {

         /* Parse current element */
         char tempChar;
         int index = (*it).length() - digit - 1;

         // If element contains value, use it
         if (index >= 0)
         {
            tempChar = (*it)[index];
         }

         // If element does not contain value, use 0
         else
         {
            tempChar = '0';
         }

         // Check if number
         if (tempChar >= '0' && tempChar <= '9') {
            number = (int)tempChar - '0';
            bucket = number;

         }

         // Check if letter
         else if (tempChar >= 'A' && tempChar <= 'Z') {
            bucket = (int)tempChar - 55;
         }

         // Invalid element
         else {
            // do nothing
         }

         /* Push value onto sorted stack */
         buckets[bucket].push(*it);

      }

      /* Clear vector */
      numbers.clear();

      /* Iterate over each bucket, putting elements back into vector */
      for (int curr = 0; curr < radix; curr++) {
         while (!buckets[curr].empty()) { // while current bucket isn't empty
            numbers.push_back(buckets[curr].front()); // insert the top value
            buckets[curr].pop(); // then remove it from the bucket
         }
      }
   }
}


#endif
