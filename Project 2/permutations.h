/* -----------------------------------------------------------------------------
                                                               Jesse Walton
                                                               U89823440
                                                               Data Structures
                                                               Project #2
----------------------------------------------------------------------------- */

#ifndef PERMUTATIONS_H_
#define PERMUTATIONS_H_

#include <cassert>
using namespace std;

template <class T>
void outputArray(T* items, const int& size, std::ostream& out)
/* -----------------------------------------------------------------------------
   Output all elements of array onto single line, separated by a space

   Preconditions: array of items and size of array
   Postconditions: NONE
----------------------------------------------------------------------------- */
{
   for(int i = 0; i < size; ++i)
   {
      out << items[i] << " ";
   }
}

long factorial(const int& n)
/* -----------------------------------------------------------------------------
   Calculate factorial of passed in value

   Precondition: None
   Postcondition: Returns long type value of n!
----------------------------------------------------------------------------- */
{
   if (n > 1)
      return (n * factorial(n - 1));
   else
      return 1;
}

template <class T>
int findPermutations(T* items, int location, const int& size, ostream& out)
/* -----------------------------------------------------------------------------
   Helper function - Determines all permutations of array

   Precondition: Must be called from outputPermutations() function
   Postcondition: Returns number of iterations run
----------------------------------------------------------------------------- */
{
   static int counter = 0;

   // Base Case:
   // End of recursive thread reached, display current array
   if(location == size)
   {
      outputArray(items, size, out);
      out << endl;
      counter++;
   }

   // Recursive Case:
   // Switch values, call recursive function with (location + 1) places fixed,
   // switch values back afterwards
   else
   {
      for(int count=location; count<size; count++)
      {
         swap(items[location], items[count]);
         findPermutations(items, (location + 1), size, out);
         swap(items[location], items[count]);
      }
   }

   return counter;
}

template <class T>
void outputPermutations(T* tArray, const int& size, ostream& out)
/* -----------------------------------------------------------------------------
   Display all permutations of given array. Asserts correct number of
   permutations based on factorial(size)

   Precondition: NONE
   Postcondition: NONE
----------------------------------------------------------------------------- */
{
   int location = 0;
   int counter = 0;

   counter = findPermutations(tArray, location, size, out);

   assert(counter == factorial(size));
}

template <class T>
void swap(T firstElement, T secondElement)
/* -----------------------------------------------------------------------------
   Helper function - Swaps two values

   Precondition: Two values are passed in by reference
   Postcondition: Passed in values are swapped
//----------------------------------------------------------------------------*/
{
   T tempElement = firstElement;
   firstElement = secondElement;
   secondElement = tempElement;
}

#endif // PERMUTATIONS_H_
