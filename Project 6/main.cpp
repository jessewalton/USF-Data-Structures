/*******************************************************************************
   Jesse Walton - 50% - BFS                                        Project #6
   Jun Moon -     50% - DFS                                        12/04/2014
   Shared - Adjacency list creation, main.cpp and
      findSolution() function used by both BFS and DFS
*******************************************************************************/

#include <iostream>
#include <fstream>
#include "Maze.h"

using namespace std;

int main() {

   int numOfMazes = 0;
   int elementValue = 0;
   int numElements;
   int squareDimension;
   int * array1D;

   // open input file stream
   ifstream inputFile;
   inputFile.open("input.txt");

   // open output file streams
   ofstream JunMoon;
   JunMoon.open("JunMoon.txt");

   ofstream JesseWalton;
   JesseWalton.open("JesseWalton.txt");

   if(inputFile.is_open()) {
      cout << "Input file open" << endl;
      inputFile >> numOfMazes;

      while (numOfMazes > 0) {

         elementValue = 0;
         squareDimension = 0;
         int size = 0;

         // read size
         inputFile >> size;
         Maze newMaze(size);

         // read in values
         inputFile >> newMaze;

         // Solve BFS, output to file
         newMaze.BFS(0);
         JunMoon << "Breadth First Search:\n";
         JunMoon << newMaze << endl;

         // Solve DFS, output to file
         newMaze.DFS();
         JesseWalton << "Depth First Search:\n";
         JesseWalton << newMaze << endl;

         // reduce number of mazes remaining
         numOfMazes--;
      }
   }

   inputFile.close();

   cout << "input file closed" << endl;

   return 0;
}
