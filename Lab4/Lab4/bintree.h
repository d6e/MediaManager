#ifndef BINTREE_H
#define BINTREE_H
#include <iostream>
#include "nodedata.h"

/* BinTree is a standard binary tree that will sort the data objects
 * as they come into the tree. Whatever comes in fist is the root the rest
 * will fall into place according to if it is less than or greater than the root.
 *
 * The NodeData is assumed that all the data is formatted correctly to the point
 * they can be compared as we go. All instances of BinTree should have all the
 * same data types.
 */
class BinTree {

// ostream is for all output
friend ostream& operator<<(ostream&, const BinTree&);

// istream is used for inputting
friend istream& operator>>(istream&, BinTree&);

public:

   /* 
    * Create a tree with or with out any NodeData
    */
   BinTree();              // No argument constructor
   BinTree( const BinTree & );   // one argument constructor
   
   ~BinTree();
   
   bool isEmpty() const;
   void makeEmpty();
   BinTree& operator=(const BinTree &);
   /*
    * Insert new data in proper order, insert should traverse
    * until there is a spot for new data to be placed.
    */
   bool insert( NodeData*); // insert new object
   /*
    * I chose a bool however we may not want a bool I felt we should
    * know if we found what it is that we are looking for so I felt
    * a true false was needed.
    * If found set true and return the string.
    * If not found return a not found message
    */
   bool retrieve( NodeData*) const; //
   
   /*
    * Display in order traversal of the whole list
    */
   void displayInOrder();  // Display the tree, calls NodeData.display();
   
private:
   /*
    * 
    */
   struct Node{
      NodeData* data;
      Node* left;
      Node* right;
   };
   
   Node* root;
   
   /*
    * size of the tree
    */
   int size;
};

#endif
