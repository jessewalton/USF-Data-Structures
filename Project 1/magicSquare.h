/*- magicSquare.h -------------------------------------------------------------
   Declaration file of the MagicSquare class that models magic squares
 ----------------------------------------------------------------------------*/

#ifndef MAGICSQUARE_H
#define MAGICSQUARE_H

#include <iostream>
#include <string>

class MagicSquare
{
	//-- Friend Functions
   friend std::ostream &operator<<(std::ostream &, const MagicSquare &);
   friend std::istream &operator>>(std::istream &, MagicSquare &);

public:

	//-- Constructors
   MagicSquare();    // default
   MagicSquare(const int& squareSize);   // user specified

	//-- Destructor
   ~MagicSquare();

	// Accessors
   int getSquareDimension();
   void setSquareElement(int, int, int);

   //-- Mutators
   void setSquareDimension(const int& dimension);

   //-- Output
   void printSquare();

   //-- Functions
   bool isMagicSquare();
   void rotate();


private:

	// called from the constructors, creates and populates magic square
   void generateMagicSquare();

	// stores magic square array dimension
   int squareDimension;

	// pointer to array location
   int** magicSquareArray;

};

#endif

