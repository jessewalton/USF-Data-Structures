/* -----------------------------------------------------------------------------
                                                               Jesse Walton
                                                               U89823440
                                                               Data Structures
                                                               Project #2
----------------------------------------------------------------------------- */

#include <iostream>
#include "permutations.h"

using namespace std;

// Function Prototypes
void testOutputArray();
void testFactorial();
void testPermutations();

int main()
{

   testOutputArray();

   testFactorial();

   testPermutations();

    return 0;
}

void testOutputArray()
/* -----------------------------------------------------------------------------
   Test Function

   Creates array of type int, double and char and passes them to
   outputArray() function.
----------------------------------------------------------------------------- */
{
   cout << "+------- Test outputArray() --------+" << endl;

   int intArraySize = 3;
   int intArray[3] = {1, 2, 3};

   int doubleArraySize = 5;
   double doubleArray[5] = {1.1, 2.2, 3.3, 4.4, 5.5};

   int charArraySize = 10;
   char charArray[10] = {'h','e','l','l','o',' ','c','a','t','\0'};

   cout << "  ";
   outputArray(intArray, intArraySize, cout);
   cout << "\n  ";
   outputArray(doubleArray, doubleArraySize, cout);
   cout << "\n  ";
   outputArray(charArray, charArraySize, cout);

   cout << "\n+-------  End outputArray() --------+\n" << endl;
}

void testFactorial()
/* -----------------------------------------------------------------------------
   Test Function

   Calls factorial() function on numbers between 0 and 9 calculating and
   displaying results.
----------------------------------------------------------------------------- */
{
   cout << "+-------- Test factorial() ---------+" << endl;

   for (int i = 0; i < 10; ++i)
   {
      cout << "  factorial(" << i << ") = "<< factorial(i) << endl;
   }
   cout << "+--------  End factorial() ---------+" << endl;

   cout << endl;

}


void testPermutations()
/* -----------------------------------------------------------------------------
   Test Function

   Creates array of type int, double and char and passes them to
   outputPermutations() function.
----------------------------------------------------------------------------- */
{
   cout << "+---- Test outputPermutations() ----+" << endl;

   int intArraySize = 3;
   int intArray[] = {1, 2, 3};

   int doubleArraySize = 4;
   double doubleArray[] = {1.1, 2.2, 3.3, 4.4};

   int charArraySize = 5;
   char charArray[] = {'a', 'b', 'c', 'd', 'e'};

   // Display all permutations of int array
   outputPermutations(intArray, intArraySize, cout);
   cout << endl;

   // Display all permutations of double array
   outputPermutations(doubleArray, doubleArraySize, cout);
   cout << endl;

   // Display all permutations of char array
   outputPermutations(charArray, charArraySize, cout);
   cout << endl;

   cout << "+---- Test outputPermutations() ----+" << endl;
}

