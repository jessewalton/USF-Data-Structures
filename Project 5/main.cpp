#include "bst.h"
#include <iostream>
using namespace std;

int main() {

   BinarySearchTree<int> a;
   BinarySearchTree<char> b;
   BinarySearchTree<string> c;
   BinarySearchTree<float> d;


// test isEmpty
   cout << "isEmpty (pre-insertion):" << endl;
   if (a.isEmpty())
      cout << "A is Empty" << endl;
   else
      cout << "A is not empty" << endl;

   if (b.isEmpty())
      cout << "B is Empty" << endl;
   else
      cout << "B is not empty" << endl;

   if (c.isEmpty())
      cout << "C is Empty" << endl;
   else
      cout << "C is not empty" << endl;

   if (d.isEmpty())
      cout << "D is Empty" << endl;
   else
      cout << "D is not empty" << endl;
   cout << endl;

// test insert
   a.insert(8);
   a.insert(7);
   a.insert(9);
   a.insert(6);
   a.insert(20);
   a.insert(10);
   a.insert(30);
   a.insert(5);

   b.insert('k');
   b.insert('l');
   b.insert('m');
   b.insert('z');
   b.insert('a');
   b.insert('b');
   b.insert('c');

   c.insert("Mary");
   c.insert("had");
   c.insert("a");
   c.insert("little");
   c.insert("lamb");


// test isEmpty
   cout << "isEmpty (post-insertion):" << endl;
   if (a.isEmpty())
      cout << "A is Empty" << endl;
   else
      cout << "A is not empty" << endl;

   if (b.isEmpty())
      cout << "B is Empty" << endl;
   else
      cout << "B is not empty" << endl;

   if (c.isEmpty())
      cout << "C is Empty" << endl;
   else
      cout << "C is not empty" << endl;

   if (d.isEmpty())
      cout << "D is Empty" << endl;
   else
      cout << "D is not empty" << endl;
   cout << endl;


// test display
   cout << "\n----------------------------\n" << endl;
   cout << "A: " << endl;
   a.displayGraphic(cout);
   cout << "\n----------------------------\n" << endl;

   cout << "B: " << endl;
   b.displayGraphic(cout);
   cout << "\n----------------------------\n" << endl;

   cout << "C: " << endl;
   c.displayGraphic(cout);
   cout << "\n----------------------------\n" << endl;

   cout << "D: " << endl;
   d.displayGraphic(cout);
   cout << "\n----------------------------\n" << endl;


// test search
   cout << "Search: " << endl;
   cout << "A: " << endl;
   int values[] = { 7, 8, 9, 10, 11 };
   for (int i = 0; i < 5; i++) {
      if(a.search(values[i])) {
         cout << "    '" << values[i] << "' found" << endl;
      }
      else {
         cout << "    '" << values[i] << "' not found" << endl;
      }
   }

   cout << "B: " << endl;
   char characters[5] = { 'a', 'f', 'k', 'l', 'z' };
   for (int i = 0; i < 5; i++) {
      if(b.search(characters[i])) {
         cout << "    '" << characters[i] << "' found" << endl;
      }
      else {
         cout << "    '" << characters[i] << "' not found" << endl;
      }
   }

   cout << "C: " << endl;
   string strings[5] = { "test", "words", "lamb", "had", "the"};
   for (int i = 0; i < 5; i++) {
      if(c.search(strings[i])) {
         cout << "    '" << strings[i] << "' found" << endl;
      }
      else {
         cout << "    '" << strings[i] << "' not found" << endl;
      }
   }

   cout << "D: " << endl;
   float floatingPt[5] = { 1.0, 1.1, 1.2, 3.0, 5.5 };
   for (int i = 0; i < 5; i++) {
      if(d.search(floatingPt[i])) {
         cout << "    '" << floatingPt[i] << "' found" << endl;
      }
      else {
         cout << "    '" << floatingPt[i] << "' not found" << endl;
      }
   }


// test min / max
   cout << "\nMinimum: " << endl;
   cout << "A:   " << a.getMinimum() << endl;
   cout << "B:   " << b.getMinimum() << endl;
   cout << "C:   " << c.getMinimum() << endl;
   cout << "D:   " << d.getMinimum() << endl;

   cout << "\nMaximum: " << endl;
   cout << "A:   " << a.getMaximum() << endl;
   cout << "B:   " << b.getMaximum() << endl;
   cout << "C:   " << c.getMaximum() << endl;
   cout << "D:   " << d.getMaximum() << endl;
   cout << endl;


// test height
   cout << "\nHeight: " << endl;
   cout << "A:   " << a.getHeight() << endl;
   cout << "B:   " << b.getHeight() << endl;
   cout << "C:   " << c.getHeight() << endl;
   cout << "D:   " << d.getHeight() << endl;
   cout << endl;


// test successor
   cout << "Successor: " << endl;
   cout << "A:   " << a.getSuccessor(20) << endl;
   cout << "B:   " << b.getSuccessor('m') << endl;
   cout << "C:   " << c.getSuccessor("had") << endl;
   cout << "D:   " << d.getSuccessor(1.0) << endl;
   cout << endl;


// test predecessor
   cout << "Predecessor: " << endl;
   cout << "A:   " << a.getPredecessor(20) << endl;
   cout << "B:   " << b.getPredecessor('m') << endl;
   cout << "C:   " << c.getPredecessor("had") << endl;
   cout << "D:   " << d.getPredecessor(1.0) << endl;
   cout << endl;


// test size
   cout << "Size: " << endl;
   cout << "A:   " << a.getSize() << endl;
   cout << "B:   " << b.getSize() << endl;
   cout << "C:   " << c.getSize() << endl;
   cout << endl;


// test preorder
   cout << "Preorder: " << endl;
   cout << "A:   "; a.preorder(cout); cout << endl;
   cout << "B:   "; b.preorder(cout); cout << endl;
   cout << "C:   "; c.preorder(cout); cout << endl;
   cout << endl;


// test inorder
   cout << "Inorder: " << endl;
   cout << "A:   "; a.inorder(cout); cout << endl;
   cout << "B:   "; b.inorder(cout); cout << endl;
   cout << "C:   "; c.inorder(cout); cout << endl;
   cout << endl;


// test postorder
   cout << "Postorder: " << endl;
   cout << "A:   "; a.postorder(cout); cout << endl;
   cout << "B:   "; b.postorder(cout); cout << endl;
   cout << "C:   "; c.postorder(cout); cout << endl;
   cout << endl;


// test copy constructor
   BinarySearchTree<int> newBST = a;

   cout << "BST to copy: " << endl;
   a.displayGraphic(cout);
   cout << "Copied BST: " << endl;
   newBST.displayGraphic(cout);
   cout << endl << endl;

// test assignment overload
   BinarySearchTree<char> newBST2;
   newBST2 = b;

   cout << "BST to copy: " << endl;
   b.displayGraphic(cout);
   cout << "Copied BST: " << endl;
   newBST2.displayGraphic(cout);
   cout << endl << endl;

// test destructor
   cout << "Destructor: " << endl;
   BinarySearchTree<int> * persistant;
   {
      BinarySearchTree<int> nonPersistant;
      nonPersistant.insert(1);
      nonPersistant.insert(2);
      nonPersistant.insert(3);
      nonPersistant.insert(4);

      persistant = &nonPersistant;

      cout << "Pre-Destructor: " << endl;
      persistant->displayGraphic(cout);

   }
   cout << "Post-Destructor: " << endl;
   persistant->displayGraphic(cout);
}

