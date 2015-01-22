#include <iostream>
#include <string>
#include <fstream>
#include "magicSquare.h"
using namespace std;



int main()
{

   const int NUMBER_OF_SQUARES = 10;


   // Create object using default constructor
   MagicSquare defaultSquare;



   // Open file output stream
   ofstream outputFile;
   outputFile.open("output.txt");



   // Open file input stream
   ifstream inputFile;
   inputFile.open("input.txt");



   // Verify square created with default constructor is valid, if so output to
   // 'output.txt' text file
   if (defaultSquare.isMagicSquare())
   {
      outputFile << defaultSquare << endl;
   }



   // Create magic squares of size 7, 9, 11, 13, 15, 17, 19, 21, 23, 25
   // for each, validate magic square attributes, rotate revalidate and
   // export depending on validity
   for (int i = 5; i < 25; )
   {
      i = i + 2;

      MagicSquare *mySquare = new MagicSquare(i);

      if (mySquare->isMagicSquare())
         outputFile << *mySquare << endl;

      mySquare->rotate();

      if (mySquare->isMagicSquare())
         outputFile << *mySquare << endl;
      else
         cout << *mySquare << endl;

      delete mySquare;
   }



   // Import squares from input.txt
   // Check if file stream is open, read in number of squares to import
   // iterate through number of squares, inputting values into array
   // check if object contains valid magic square
   int squaresToInput = 0;
   int elementValue = 0;
   int squareDimension = 0;
   int squareCounter = 0;

   if (inputFile.is_open())
   {
      inputFile >> squaresToInput;

      while (squaresToInput > 0)
      {
         elementValue = 0;
         squareDimension = 0;

         inputFile >> squareDimension;

         MagicSquare inputSquare(squareDimension);

         for (int row = 0; row < squareDimension; row++)
         {
            for (int col = 0; col < squareDimension; col++)
            {
               inputFile >> elementValue;
               inputSquare.setSquareElement(row, col, elementValue);
            }
         }

         cout << squareCounter << ": ";
         if(inputSquare.isMagicSquare())
            cout << "is valid" << endl;
         else
            cout << "is not valid" << endl;

         squaresToInput--;
         squareCounter++;

        }
    }

   outputFile.close();
   inputFile.close();

   return 0;

}

