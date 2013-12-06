#pragma once
#ifndef BINTREE_H
#define BINTREE_H
#include <iostream>
#include <string>
#include "nodedata.h"

/*BinTree is a standard binary tree that will sort inputted data objects as 
nodes. The first inputted data becomes is the root, and the rest are sorted by 
applying their comparison operators to existing nodes, sorting smaller-valued
data "left", higher-valued data "right", and not inserting data that is equal to
existing data.
 
The NodeData stored in each Node is of a general type, meaning the bintree
can store any kind of data that can inherit from the nodedata class, and 
meaningfully sort this data as long as its instances have meaningful comparison
operators, and as long all data in the bintree is of the same type. (For 
example, a bintree of ComedyMovies is sorted first by title, then by date.)

The << operator displays each item in the tree in sorted order. In order for it
to work, the type of NodeData in the tree mus have a << operator as well. It
calls displayInOrder() to help sort the tree's data in the proper order.

BinTree's destructor calls makeEmpty(), which recursively deletes nodes and
their nodeData from the bottom up.

isEmpty() only needs to check the root of the tree to determine whether it is 
empty, since a NULL root should always mean an empty tree.

BinTree's = operator calls makeEmpty(), and then populates the tree with the
same data as the right hand side of the expression. The latter process should
work the same in the copy constructor.

The insert() function attempts to insert a new node created from the NodeData
arg, and returns true if the node was successfully inserted (i.e., if there are
no duplicates according to the == operator). 

When the tree is used to store 
Products, each inserted Product is sorted based on its sorting order (ex: date,
then famous actor), and if a duplicate is found, the Product stored in the 
existing Node has its quantity incremented by some number (currently 10) which
represents the quantity of each Product entered into the system.

retrieve() searches the tree for a NodeData using its comparison operators, 
returning false if it is not found and true if it is. It should return false
immediately if the data searched is not of the same type contained in the tree
(for instance, searching for a book in a tree of comedy movies).
*/

class BinTree {

// ostream is for all output
friend std::ostream& operator<<(std::ostream&, const BinTree&);

   
private:
    struct Node{
        NodeData* data;
        Node* left;
        Node* right;

        Node();
        Node(const Node& otherNode);
        ~Node();
    };
    Node* root;
    // string displaying the tree (helper for <<)
    std::string displayInOrder() const;  

public:

    BinTree();              // No argument constructor
    BinTree(const BinTree & );   // copy constructor

    virtual ~BinTree();            //destructor

    bool isEmpty() const;  //checks if the tree is empty
    void makeEmpty();      //makes the tree empty
    void makeEmpty(Node*);      //makes the tree empty
    BinTree& operator=(const BinTree &);  //sets the tree equal to another tree

    bool insert( NodeData*); // insert new object
    bool retrieve( NodeData*) const; //searches the Tree for a NodeData object

    int getSize() const;        //returns the number of nodes in the tree

};

#endif
