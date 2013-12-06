#pragma once
#ifndef BINTREE_H
#define BINTREE_H
#include <iostream>
#include <string>
#include <vector>
#include "nodedata.h"

/*BinTree is a standard binary tree that will sort inputted data objects as 
nodes. The first inputted data becomes is the root, and the rest are sorted by 
applying their comparison operators to existing nodes, sorting smaller-valued
data "left", higher-valued data "right", and not inserting data that is equal to
existing data.
*/

class BinTree {

// std::ostream is for all output
friend std::ostream& operator<<(std::ostream&, const BinTree&);

public:

    BinTree();                     // default constructor
    BinTree(const BinTree & );     // copy constructor
    virtual ~BinTree();            // destructor

    BinTree& operator=(const BinTree &);//assignment operator

    bool isEmpty() const;      //checks if the tree is empty
    void makeEmpty();          //deletes all trees
    bool insert(NodeData*);    // insert nodedata obj
    bool retrieve(const NodeData*) const; //checks if nodedata obj exists

    std::string getName() const; // returns full name of product
    std::vector<std::string> getDataTypes() const;
    int getDataTypeSize() const; // accessor for product datatypes
private:
    struct Node {
        ~Node();
        NodeData* data;
        Node* left;
        Node* right;
    };
    Node* root;
    // for displaying tree contents
    std::string displayInOrder() const;
    bool insert(NodeData*,Node*,Node*,bool); //insert helper
    void displayHelper(std::ostream&,Node*) const; //helper
    void makeEmpty(Node*);                          // helper
    bool retrieve(Node*,const NodeData*) const; //helper
};

#endif
