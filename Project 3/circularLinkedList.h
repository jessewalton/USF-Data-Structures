// Jesse Walton
// circularLinkedList.h

//#ifndef CIRCULARLINKEDLIST_H_
//#define CIRCULARLINKEDLIST_H_

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template <class T>
class List {

   private:
      class Node {
         public:
            T data;
            Node * next;
      };

   public:
      List();
      List(const List&);
      ~List();
      int getSize() const;
      int getCapacity() const;
      bool isEmpty() const;
      bool insert(const T&, const int&);
      bool remove(const int&);
      const List& operator=(const List&);
      void display(ostream &) const;
      friend ostream& operator<<(ostream&, const List<T>&);
      T runJosephusAlgorithm();

   private:
      bool deleteList(Node *);
      bool copyList(Node *, Node * &);
      Node * _first;
};

//#endif

// Josephus Algorithm
template<class T>
T List<T>::runJosephusAlgorithm() {

   List * tempFirst = this;
   List * tempList = this;

   while (tempList->getSize() != 1)
   {
      int size = tempList->getSize();
      int startNode = rand() % size;
      int counter = rand() % (size * 2);

      int delPosition = (startNode + counter) % size;

      tempList->remove(delPosition);
   }
}

// Default Constructor
template <class T>
List<T>::List() {
   _first = 0;
}

// Copy Constructor
template <class T>
List<T>::List(const List& originalList) {
   _first = 0;
   copyList(originalList._first, _first);
}

// Destructor
template <class T>
List<T>::~List() {
   deleteList(_first);
}

// Overload Assignment Operator
template <class T>
const List<T>& List<T>::operator=(const List& rhs) {
   if(this == &rhs) {
      return *this;
   }
   //_size = rhs._size;
   copyList(rhs._first, _first);
   return *this;
}

// Overload << Operator
template <typename T>
ostream& operator<<(ostream& out, const List<T>& list) {
   list.display(out);

   return out;
}

// Get Size of List
template <class T>
int List<T>::getSize() const {
   int counter = 0;
   Node * ptr = _first;

   if (_first == 0)
      return 0;

   do {
      ptr = ptr->next;
      counter++;
   } while(ptr != _first);

   return counter;
}

// Insert Node
template <class T>
bool List<T>::insert(const T& item, const int& position) {

   // verify that this is an acceptable position
   if (position < 0) {
      return false;
   }

   // create a new node with the specified data
   Node * newNode = new Node;
   newNode->data = item;
   newNode->next = 0;

   // if inserting at beginning
   if (position==0) {

      // if no nodes exist
      if (_first==0) {              // if the list is empty

         newNode->next = newNode;   // have newNode point to itself
         _first = newNode;          // point to newNode

      // if nodes exist
      } else {

         Node * pred;
         pred = _first;

         do {
            pred = pred->next;
         } while (pred->next != _first);
         pred->next = newNode;
         newNode->next = _first;
      }
   }

   // if inserting anywhere else
   else {

      int counter = 0;
      Node * predPtr = _first;

      // works, but keeps looping around
      for (int i=1; i<position; ++i) {
         predPtr = predPtr->next;
      }

      // insert the new element
      newNode->next = predPtr->next;
      predPtr->next = newNode;
   }
   return true;
}

// Delete Node
template <class T>
bool List<T>::remove(const int& position) {

// verify we can delete an element
   if (_first==0) {
      return false;
   }

   // verify this is a valid item to delete
   if (position<0) {
      return false;
   }

   // the first item is a special case
   if (position==0) {

      Node * ptr = _first;
      do {
         ptr = ptr->next;
      } while (ptr->next != _first);
      ptr->next = ptr->next->next;
      _first = ptr->next;

   } else {
   int counter = 0;
   Node * ptr = _first;
   Node * predPtr;

   do {
      predPtr = ptr;
      ptr = ptr->next;
      counter++;

   } while (counter != position && ptr->next != _first);

   if (ptr->next != _first) {
      predPtr->next = ptr->next;
   }
   else
   {
      return false;
   }

   delete ptr;

   return true;

}

}

// Check if empty
template <class T>
bool List<T>::isEmpty() const {
   return _first == 0;
}




// Delete List
template <class T>
bool List<T>::deleteList(Node * firstPtr) {

   // if there are no nodes
   if (firstPtr == 0) {
      return true;
   }

   // if there are more than one nodes
   if (firstPtr != firstPtr->next)
   {
      Node * iteratorPtr = firstPtr;
      do {
         Node *tempPtr = iteratorPtr;
         iteratorPtr = iteratorPtr->next;
         firstPtr = iteratorPtr; // reassign first as iterator moves along
         delete tempPtr; // delete node before iterator location
      } while (iteratorPtr->next != iteratorPtr); // continue until one remains
   }

   // delete last node
   firstPtr = 0;
   delete firstPtr;
   return true;
}

// Display List
template <class T>
void List<T>::display(ostream& out) const {
   Node* ptr = _first;
   if(ptr != 0) { // if list is not empty
      do {
         out << ptr->data << " ";   // output current pointer data
         ptr = ptr->next;           // move to next pointer
      } while (ptr != _first );
   }
}

// Copy List
template <class T>
bool List<T>::copyList(Node * originalListFirst, Node * &copiedListFirst) {
   // if the original list is empty, then simply delete the anything held in
   // the copied list
   if (originalListFirst == 0) {
      deleteList(copiedListFirst);
      return true;
   }

   // if there is already a list held where the copied list should go, then
   // delete that list
   deleteList(copiedListFirst);

   // copy the data from the first node
   copiedListFirst = new Node;
   copiedListFirst->data = originalListFirst->data;
   copiedListFirst->next = copiedListFirst;

   // create a pointer to the current location in each list
   Node * originalPtr = originalListFirst;
   Node * copiedPtr = copiedListFirst;

   // copy the data in the remaining nodes
   do {
      copiedPtr->next = new Node;
      originalPtr = originalPtr->next;
      copiedPtr = copiedPtr->next;

      copiedPtr->data = originalPtr->data;
      copiedPtr->next = copiedListFirst;
   } while (originalPtr->next!=originalListFirst);

   return true;
}

