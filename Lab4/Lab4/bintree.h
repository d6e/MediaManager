#ifndef BINTREE_H
#define BINTREE_H
#include <iostream>
#include "nodedata.h"
using namespace std;


class BinTree {

// We may not need these at all I was not sure how we are reading in.
// ostream is for all output
friend ostream& operator<<(ostream&, const BinTree&);

// istream is used for inputting
friend istream& operator>>(istream&, BinTree&);

public:

   /* 
    * Create a tree with or with out any NodeData
    */
   BinTree();              // No argument constructor
   BinTree( NodeData* );   // one argument constructor
   /*
    * Insert new data in proper order, insert should traverse
    * until there is a spot for new data to be placed.
    */
   void insert( NodeData*); // insert new object
   /*
    * I chose a bool however we may not want a bool I felt we should
    * know if we found what it is that we are looking for so I felt
    * a true false was needed.
    * If found set true and return the string.
    * If not found return a not found message
    */
   bool retrive( String sortKeys ) //
   
   /*
    * Display in order traversal of the whole list
    */
   void diplayInOrder();  // Display the tree
   
   /*
    * return size
    */
   int getSize() const;
   
private:
   /*
    * The pointer to the tree
    */
   int* BinTreePtr;
   
   /*
    * size of the tree
    */
   int size;
};

#endif
