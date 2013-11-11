
#ifndef BINTREE_H
#define BINTREE_H
#include <iostream>
#include "nodedata.h"
using namespace std;


class BinTree {

// ostream is for all output
friend ostream& operator<<(ostream&, const BinTree&);

// istream is used for inputting
friend istream& operator>>(istream&, BinTree&);

public:

   BinTree();              // No argument constructor
   BinTree( NodeData* );   // one argument constructor
   
   void insert( NodeData*); // insert new object
   bool retrive( String sortKeys ) //
   
   void diplayInOrder();  // Display the tree
   
   int getSize() const;
   
private:

   int* BinTreePtr;
   int size;
};

#endif
