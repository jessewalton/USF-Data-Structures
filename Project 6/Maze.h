#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Maze {

   friend std::ostream &operator<<(std::ostream &, Maze &);
   friend std::istream &operator>>(std::istream &, Maze &);

public:

   // Constructor
   Maze(int n);

   // Accessors
   int getDimension();
   int getSize();

   // Traversal Algorithms
   void BFS(const int& s);
   void DFS();

private:

   // class helper functions
   void getAdjacentcies();
   void assignHorizontalVertical(int index, int value);
   void assignDiagonals(int index, int value);
   void findSolution(const vector<int>& parent, const int& variable);
   vector<string> returnSolution() { return solution;}

   // class variables
   int dimension;
   int size;
   vector<int> storage;
   vector<vector<int> > adjacencyList;
   vector<string> solution;

};

/*******************************************************************************
Allows output of Maze solutions using the overloaded << stream operators

Precondition:   << is overloaded to work with Maze objects in addition
      to regular usage of <<
Postcondition:  Most recently solved maze is output
*******************************************************************************/
ostream &operator<<(ostream &output, Maze &maze)
{
   vector<string>::iterator sol;
   for (sol = maze.solution.begin(); sol != maze.solution.end(); sol++) {
      output << *sol << " ";
   }
   return output;
}

/*******************************************************************************
Allows input of Maze objects using the overloaded >> stream operators

Precondition:   >> is overloaded to work with Maze objects in addition
      to regular usage of >>
Postcondition:  Adjacency list is populated
*******************************************************************************/
istream &operator>>(istream &input, Maze &maze)
{
   // Read in elements
   for (int i = 0; i < maze.getSize(); i++) {
      int currentElement;
      input >> currentElement;
      maze.storage.push_back(currentElement);
   }

   // copy elements to the 2nd half of adj. list
   for (int i = 0; i < maze.getSize(); i++) {
      maze.storage.push_back(maze.storage[i]);
   }

   // call helper function to calculate adjacencies
   maze.getAdjacentcies();

   // return input to allow cascading
   return input;
}


/*******************************************************************************
Helper Function: Populates Adjacency List

Precondition:   Storage vector must be populated with 2n^2 values
Postcondition:  adjacencyList contains horiz/vert adjacencies on indices
   0 to (n^2)-1 and diagonal adjacencies on indices n^2 to (2n^2)-1
*******************************************************************************/
void Maze::getAdjacentcies() {

// parse horizontal/vertical and diagonal
// add new row
   for (int i = 0; i < getSize() * 2; i++) {
      vector<int> newVector;
      adjacencyList.push_back(newVector);

      int element = storage[i];
      int elementAbs = abs(element);

      // assign horizontal and vertical to elements from
      // 0 to n^2-1
      if (i < getSize()) {

         //check and assign horiz. / vert. adjacencies
         assignHorizontalVertical(i, elementAbs);

      // assign diagonal adjacencies to elements from
      // n^2 to 2n^2-1
      } else {
         // check and assign diagonal adjacencies
         assignDiagonals(i, elementAbs);
      }
   }
}

/*******************************************************************************
Helper Function: Populate indices 0 to (n^2)-1 with horizontal and vertical
      adjacencies.

Precondition:   Must be called from getAdjacencies()
Postcondition:  adjacencyList[i] contains horizontal and vertical adjacencies
*******************************************************************************/
void Maze::assignHorizontalVertical(int i, int nodeValue) {

   int n = dimension;
   int offset = size;

   // determine current row and column
   int currRow = i / getDimension();
   int currCol = i % getDimension();

   // check north
   int N = currRow - nodeValue;
   if(N < 0) {
      adjacencyList[i].push_back(-1);
   } else {
      // calculate next index, add it to H/V adjacency list
      N = i - (nodeValue * n);

      // if value at n is negative... how do we test for that?
      if (storage[N] < 0 ) {
         adjacencyList[i].push_back(N+offset);
      } else {
         adjacencyList[i].push_back(N);
      }
   }

   // check south
   int S = currRow + nodeValue;
   if (S > (n-1)) {
      // out of bounds, do nothing
      adjacencyList[i].push_back(-1);
   } else {
      // calculate next index, add it to H/V adjacency list
      S = i + (nodeValue * n);

       // if value at n is negative... how do we test for that?
      if (storage[S] < 0 ) {
         adjacencyList[i].push_back(S+offset);
      } else {
         adjacencyList[i].push_back(S);
      }
   }

   // check west
   int W = currCol - nodeValue;
   if(W < 0) {
      // out of bounds, do nothing
      adjacencyList[i].push_back(-1);
   } else {
      // calculate next index, add it to H/V adjacency list
      W = i - nodeValue;

      // if value at n is negative... how do we test for that?
      if (storage[W] < 0 ) {
         adjacencyList[i].push_back(W+offset);
      } else {
         adjacencyList[i].push_back(W);
      }
   }

   // check east
   int E = currCol + nodeValue;
   if(E > (n-1)) {
      // out of bounds, do nothing
      adjacencyList[i].push_back(-1);
   } else {
      // calculate next index, add it to H/V adjacency list
      E = i + nodeValue;

      // if value at n is negative... how do we test for that?
      if (storage[E] < 0 ) {
         adjacencyList[i].push_back(E+offset);
      } else {
         adjacencyList[i].push_back(E);
      }
   }
}

/*******************************************************************************
Helper Function: Populate indices n^2 to (2n^2)-1 with diagonal adjacencies.

Precondition:   Must be called from getAdjacencies()
Postcondition:  adjacencyList[i] contains diagonal adjacencies
*******************************************************************************/
void Maze::assignDiagonals(int i, int nodeValue) {

   int n = dimension;
   int offset = size;

   // determine current row and column
   int currRow = i / n;
   currRow = currRow % n;
   int currCol = i % n;

   // Check NORTH WEST
   if((currRow - nodeValue) < 0 || (currCol - nodeValue) < 0) {

      // new value is out of bounds,
      // push -1 placeholder onto stack
      adjacencyList[i].push_back(-1);

   } else {

      // new value is in bounds
      // find index
      int NW = (i - (nodeValue*n) - nodeValue);

      // if original value is negative, switch to H/V adjacency list
      // push to stack
      if (storage[NW] < 0) {
         adjacencyList[i].push_back(NW-offset);
      } else {
         adjacencyList[i].push_back(NW);
      }
   }

   // check NORTH EAST
   if((currRow - nodeValue) < 0 || (currCol + nodeValue) > (n-1)) {
      // out of bounds
      adjacencyList[i].push_back(-1);
   } else {

      int NE = (i - (nodeValue * n) + nodeValue);

      if (storage[NE] < 0 ) {
         adjacencyList[i].push_back(NE-offset);
      } else {
         adjacencyList[i].push_back(NE);
      }
   }

   // check SOUTH WEST
   if((currRow + nodeValue) > (n-1) || (currCol - nodeValue) < 0) {
      // out of bounds
      adjacencyList[i].push_back(-1);
   } else {

      int SW = (i + (nodeValue * n) - nodeValue);

      if (storage[SW] < 0 ) {
         adjacencyList[i].push_back(SW-offset);
      } else {
         adjacencyList[i].push_back(SW);
      }
   }

   // check SOUTH EAST
   if((currRow + nodeValue) > (n-1) || (currCol + nodeValue) > (n-1)) {
      //out of bounds
      adjacencyList[i].push_back(-1);
   } else {

      int SE = (i + (nodeValue * n) + nodeValue);

      if (storage[SE] < 0 ) {
         adjacencyList[i].push_back(SE-offset);
      } else {
         adjacencyList[i].push_back(SE);
      }
   }
}

/*******************************************************************************
Records directions taken by search algorithms

Precondition:   Must be called
Postcondition:  Adjacency list is populated
*******************************************************************************/
void Maze::findSolution(const vector<int>& parent, const int& variable) {

   vector<int> tempSol;
   stack<int> myStack;
   int temp = variable;
	int counter = 0;

   vector<int>::const_iterator it;
   vector<int>::iterator it1;

	//help to store the relevant parents responsible for making the path
	myStack.push(variable);
   while(temp!=0)
   {
      for(it=parent.begin();it!=parent.end();++it)
		{
         if(counter==temp)
		   {
            myStack.push(*it);
            temp=*it;
            counter=0;
            it=parent.begin();
		   }
         ++counter;
		}
    }

	//store in stack to find the correct order of the parents
   while(!myStack.empty())
   {
      temp = myStack.top();
      myStack.pop();

      tempSol.push_back(temp);
   }

	//display the encoded solution in cardinal directions
   for(it1=tempSol.begin();it1!=tempSol.end()-1;++it1)
   {
      temp = *it1;
      vector<int>::iterator sub = it1+1;
      int c = *sub;

      for(int i=0;i<4;++i)
      {
         if(temp<size)
         {
            if(adjacencyList[temp][i]==c)
            {
               if(i==0)
               {
					   solution.push_back("N");
					}
               else if(i==1)
               {
					   solution.push_back("S");
					}
               else if(i==2)
					{
                  solution.push_back("W");
					}
               else if(i==3)
					{
                  solution.push_back("E");
					}
            }
         }
         else
         {
            if(adjacencyList[temp][i]==c)
            {
               if(i==0)
               {
					   solution.push_back("NE");
               }
               else if(i==1)
               {
					   solution.push_back("NW");
					}
               else if(i==2)
					{
                  solution.push_back("SE");
					}
               else if(i==3)
					{
                  solution.push_back("SW");
					}
            }
         }
      }
   }
}

/*******************************************************************************
   Constructor

   Precondition: None
   Postcondition: Maze object instantiated with size and dimension variables
*******************************************************************************/
Maze::Maze(int n) {
   dimension = n;
   size = n * n;
}

/*******************************************************************************
   Accessor functions
*******************************************************************************/

int Maze::getDimension() {
   return dimension;
}

int Maze::getSize() {
   return size;
}

/*******************************************************************************
Depth First Search - by Jesse Walton

Precondition:   Adjacency List must be populated
Postcondition:  Solution path is saved in vector<string> solutions
*******************************************************************************/
void Maze::DFS()
{
   solution.clear();
	stack<int> myStack;
	vector<int> parent;
	vector<int> color;
	vector<vector<int> >::iterator pRow;
	vector<int>::iterator pCol;

	int currLocation;
	int finish_1 = size - 1; // store finish index of H/V map
	int finish_2 = (2 * size) - 1; // store finish index of DIAG. map

   // seed starting location onto stack
	myStack.push(0);

	// Initialize color and parent vector to null values (white)
	for(int i=0;i<2*size;++i)
	{
	   color.push_back(-1);
	   parent.push_back(-1);
	}

	//keep traversing through as deep as the vertex will allow with the
	//connected neighbors
	while(!myStack.empty())
	{
      currLocation = myStack.top(); myStack.pop();

	   //if solution was found then find order of parents
	   if(currLocation == finish_1 || currLocation == finish_2) {
         findSolution(parent, currLocation);
      }

      //keep traversing through neighbors
	   else
	   {
         color[currLocation] = 1;
         pRow = adjacencyList.begin() + currLocation;
         for(pCol = pRow->begin(); pCol != pRow->end(); ++pCol)
         {
            if(*pCol>0)
            {
               if(color[*pCol] !=1)
               {
                  myStack.push(*pCol);
                  parent[*pCol] = currLocation;
               }
            }
         }
	   }
   }
}

/*******************************************************************************
Breadth First Search - by Jun Moon

Precondition:   Adjacency List must be populated
Postcondition:  Solution path is saved in vector<string> solutions
*******************************************************************************/
void Maze::BFS(const int& s)
{
   solution.clear();
   queue<int> bfsQueue;
   vector<int> distance;
   vector<int> color;
   vector<int> parent;
   int variable;
   int answer = size-1;
   int squaredAnswer=(2*size)-1;

   vector<vector<int> >::iterator pRow;
   vector<int>::iterator pCol;

   //initialize
   for(int i=0;i<squaredAnswer+1; ++i)
   {
       color.push_back(-1);
       parent.push_back(-1);
       distance.push_back(-1);
   }

   color[s]=0;
   bfsQueue.push(s);

   //find all the adjacent vertexs
   while(!bfsQueue.empty())
   {
      variable = bfsQueue.front();
      bfsQueue.pop();
	  //if path was found find the parents
      if(variable == answer || variable == squaredAnswer)
      {
         findSolution(parent,variable);
      }
      //else keep traversing through all the neighbors
      else
      {
         pRow=adjacencyList.begin()+variable;
         for(pCol=pRow->begin();pCol!=pRow->end();++pCol)
         {
            if(*pCol>=0)
            {
               if(color[*pCol] ==-1)
               {
                  color[*pCol] =0;
                  bfsQueue.push(*pCol);
                  parent[*pCol]=variable;
                  distance[*pCol]=distance[variable]+1;
               }
            }
         }
      }
      color[variable]=1;
   }
}

#endif
