/*- magicSquare.cpp -----------------------------------------------------------
   Implementation file of the MagicSquare class that models magic squares
 ----------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <cassert>
#include <string>
#include "magicSquare.h"
using namespace std;

#define ASSERT true
const int DEFAULT_SQUARE_SIZE = 5;



ostream &operator<<(ostream &output, const MagicSquare &square)
/*-----------------------------------------------------------------------------
Allows output of MagicSquare objects using the overloaded << stream operators

Precondition:   << is overloaded to work with MagicSquare objects in addition
      to regular usage of <<
Postcondition:  Allows cascading
-----------------------------------------------------------------------------*/
{
   output << square.squareDimension << endl;
   for (int row = 0; row < square.squareDimension; row++)
   {
      for (int col = 0; col < square.squareDimension; col++)
      {
         output << square.magicSquareArray[row][col] << " ";
      }
      output << endl;
   }
   return output;
}



istream &operator>>(istream &input, MagicSquare &magic)
/*-----------------------------------------------------------------------------
Allows input of MagicSquare objects using the overloaded >> stream operators

Precondition:   >> is overloaded to work with MagicSquare objects in addition
      to regular usage of >>
Postcondition:  Allows cascading
-----------------------------------------------------------------------------*/
{
   // Read in new array size
   int newArraySize = 0;
   input >> newArraySize;



   // Create dynamic array based on user input
   int** newArray = new int*[newArraySize];
   for (int i = 0; i < newArraySize; i++)
   {
      newArray[i] = new int[newArraySize];
   }



   // Read in array values
   for (int i = 0; i < newArraySize; i++)
   {
      for (int j = 0; j < newArraySize; j++)
      {
         input >> newArray[i][j];
      }

   }



   // deallocate original magicSquareArray
   for (int i = 0; i < magic.getSquareDimension(); i++)
   {
      delete[] magic.magicSquareArray[i];
   }
   delete[] magic.magicSquareArray;



   // Assign new square to old
   magic.setSquareDimension(newArraySize);
   magic.magicSquareArray = newArray;



   // return input to allow cascading
   return input;
}



MagicSquare::MagicSquare()
/*-----------------------------------------------------------------------------
Default Constructor

Precondition:   DEFAULT_SQUARE_SIZE must be set
Postcondition:  MagicSquare object is created with correctly formatted magic
    square of size DEFAULT_SQUARE_SIZE
-----------------------------------------------------------------------------*/
{
   setSquareDimension(DEFAULT_SQUARE_SIZE);
   generateMagicSquare();
}



MagicSquare::MagicSquare(const int& dimension)
/*-----------------------------------------------------------------------------
Overloaded Constructor

Precondition:   Must pass in dimension of magic square
Postcondition:  MagicSquare object is created with correctly formatted magic
    square of size dimension
-----------------------------------------------------------------------------*/
{
   setSquareDimension(dimension);
   generateMagicSquare();
}



MagicSquare::~MagicSquare()
/*-----------------------------------------------------------------------------
Destructor

Precondition:   None
Postcondition:  MagicSquare object is destroyed after deallocating dynamically
    allocated memory
-----------------------------------------------------------------------------*/
{
   int dimension = getSquareDimension();

   for (int i = 0; i < dimension; i++)
   {
      delete[] magicSquareArray[i];
   }
   delete[] magicSquareArray;
}


// -- Mutators

void MagicSquare::setSquareDimension(const int& n)
/*-----------------------------------------------------------------------------
Set object's square dimension size

Precondition:  None
Postcondition: Object squareDimension size is updated.
-----------------------------------------------------------------------------*/
{
   squareDimension = n;
}



int MagicSquare::getSquareDimension()
/*-----------------------------------------------------------------------------
Returns object's square dimension size

Precondition:   None
Postcondition:  None
-----------------------------------------------------------------------------*/
{
   return squareDimension;
}



void MagicSquare::generateMagicSquare()
/*-----------------------------------------------------------------------------
Called only by constructors to dynamically allocate array space and assign
values to create a valid magic square

Precondition:   None
Postcondition:  Object holds a valid magic square array
-----------------------------------------------------------------------------*/

{

   // Get square dimension and assert that it is odd --------------------------

   // get square dimension
   int dimension = getSquareDimension();

   // assert number is odd
   if (ASSERT)
      assert((dimension % 2) == 1);

   //**************************************************************************



   // Create Array ------------------------------------------------------------

   // Create array of pointers, assign to pointer within object

   //int** magicSquareArray;
   magicSquareArray = new int*[dimension];

   // Iterate through array, create new array in each element
   for (int i = 0; i < dimension; i++)
   {
      magicSquareArray[i] = new int[dimension];
   }

   //**************************************************************************



   // ----------------------------------

   int row = 0, col = 0; // matrix place holders: magicSquare[row][col]
   int count = 1; // used to fill in matrix values, max value = dimension^2
   bool addRow = false; // special condition tag, indicates filled element

   // Assigns values in numerical order, based on the magic square formula.
   // Loop executes dimension^2 times and finishes when all elements are filled
   for (int x = 0; x < dimension * dimension; x++)
   {

      // initial condition - sets starting position to top row, middle column
      if (count == 1)
      {
         col = dimension / 2;
      }

      // default condition - executes for the rest of the iterations and
      // determines correct location of current 'count' number
      else
      {
         // If addRow is true, the box to be filled is already occupied.
         // Change target location by moving down one row
         if (addRow)
         {
            row++;
            addRow = false;
         }

         // If addRow is false, the box to be filled is empty
         // This is the default mode
         else
         {

            // subtract a row, if check to keep within bounds
            if (row == 0)
            {
               row = dimension;
            }
            row = row - 1;


            // iterate column, mod to keep within bounds
            col = (col + 1) % dimension;
         }
      }


      // assign current count to matrix location
      magicSquareArray[row][col] = count;

      // Iterate number counter
      count++;


      // Check counter for conflicting element values, set 'addRow' to true
      // to compensate for this condition in the next cycle.
      if ((count % dimension) == 1)
      {
         addRow = true;
      }
   }

   //**************************************************************************



}



void MagicSquare::printSquare()
/*-----------------------------------------------------------------------------
Precondition:  None
Postcondition: Displays 2d array of magic square values
-----------------------------------------------------------------------------*/
{
   int dimension = getSquareDimension();

   // Print matrix
   for (int row = 0; row < dimension; row++)
   {
      for (int col = 0; col < dimension; col++)
      {
         cout << magicSquareArray[row][col] << "\t";
      }
      cout << endl;
   }
}




bool MagicSquare::isMagicSquare()
/*-----------------------------------------------------------------------------
Checks for all numbers between 1 and n^2 also sums all rows and colums and
checks that they sum to [ (n(n^2+1)) / 2 ]

Precondition:  None
Postcondition: Returns bool type if MagicSquare object contains a valid magic
    square.
-----------------------------------------------------------------------------*/
{

   // #1 - all rows and columns add up to x = [ n(n^2 + 1) ] / 2
   int dimension = squareDimension;
   int diagnalCount = dimension;
   int magicSquareSum = ((dimension * ((dimension * dimension) + 1)) / 2);
   int rowSum = 0;
   int colSum = 0;
   int diagnalSumOne = 0;
   int diagnalSumTwo = 0;
   int correctSumValues = 0;
   int neededCorrectSumValues = (dimension + dimension) + 2;



   // Check row and column sums
   for (int i = 0; i < dimension; i++)
   {
      for (int j = 0; j < dimension; j++)
      {
         rowSum += magicSquareArray[i][j]; // sum row
         colSum += magicSquareArray[j][i]; // sum column
      }

      if (rowSum == magicSquareSum) // check row value
         correctSumValues++;

      if (colSum == magicSquareSum) // check col value
         correctSumValues++;

      rowSum = 0; // reset rowSum counter
      colSum = 0; // reset colSum counter
   }

   // Check diagonal sums
   for (int i = 0; i < dimension; i++)
   {
      diagnalSumOne += magicSquareArray[i][i];
      diagnalSumTwo += magicSquareArray[--diagnalCount][i];
   }


   if (diagnalSumOne == magicSquareSum)
      correctSumValues++;

   if (diagnalSumTwo == magicSquareSum)
      correctSumValues++;





   // #2 - all numbers between 1 and n^2 are used only once
   int foundNumbers = 0;
   int numbersToFind = squareDimension * squareDimension;

   for (int count = 1; count < (squareDimension*squareDimension) + 1; count++)
   {
      for (int row = 0; row < squareDimension; row++)
      {
         for (int col = 0; col < squareDimension; col++)
         {
            if (magicSquareArray[col][row] == count)
            {
               // number has been found
               foundNumbers++;

            }
         }
      }
   }


   // Determine if both cases are met
   if (correctSumValues == neededCorrectSumValues)
   {
      if (foundNumbers == numbersToFind)
      {
         return true;
      }
   }
   return false;
}



void MagicSquare::rotate()
/*-----------------------------------------------------------------------------
Precondition:   None
Postcondition:  Restructures internal magic square array by rotating all values
    by 90 degrees
-----------------------------------------------------------------------------*/
{

   int row = 0, col = 0;

   // new 1D array to temporarily store elements
   int* tempArray = new int[squareDimension*squareDimension];

   // fill array
   for (int count = 0; count < (squareDimension * squareDimension); count++)
   {


      tempArray[count] = magicSquareArray[row][col];

      if (col == (squareDimension - 1))
      {
         row++;
         row = row % squareDimension;
      }

      col++;
      col = col % squareDimension;

   }





   row = 0, col = (squareDimension - 1);

   for (int count = 0; count < (squareDimension * squareDimension); count++)
   {

      magicSquareArray[row][col] = tempArray[count];


      if (row == (squareDimension - 1))
      {
         col--;
         col = col % squareDimension;
      }

      row++;
      row = row % squareDimension;


   }

   delete[] tempArray;

}



void MagicSquare::setSquareElement(int row, int col, int value)
/*-----------------------------------------------------------------------------
Precondition:  None
Postcondition: Set specific element in magic square array based on row and col
    values specified.
-----------------------------------------------------------------------------*/
{
   magicSquareArray[row][col] = value;
}


// -- Unused functions - Not complete

/*
// Overloaded Assignment Operator
// DO NOT USE, SOMETHING WRONG WITH DYNAMIC MEMORY MANAGEMENT
MagicSquare& MagicSquare::operator=(const MagicSquare &square)
{
   if (this == &square)
   {
      return *this;
   }

   this->magicSquareArray = square.magicSquareArray;
   this->squareDimension = square.squareDimension;
   return *this;
}
*/



/*
// Copy Constructor
MagicSquare::MagicSquare(const MagicSquare &square)
{
   magicSquareArray = square.magicSquareArray;

}
*/
