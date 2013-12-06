#pragma once
#ifndef PRODUCTCOLLECTION_H
#define PRODUCTCOLLECTION_H
#include "error.h"
#include "product.h"
#include "bintree.h"
#include "productcollection.h"
#include <string>

/* 
The ProductCollection function will collect information about the product and
insert the data into a linked list. This class has basic linked list function
insert, retrieve, and print 
*/

class ProductCollection{
	friend std::ostream & operator<<(std::ostream &, const ProductCollection &);    
private:
    BinTree collection[26];
    Error displayDataTypes(const BinTree &) const; //TODO: REWRITE
    int collectionSize; //number of nodes in the collection
public:
	ProductCollection(); //default constractor
	virtual ~ProductCollection(); //default destructor 
	Error insert(Product *); //inset product into a linked list 
	Error retrieve(Product *); //retrieve product from a linked list 
	Error displayAll() const; //display all the products 
	bool isEmpty() const; //check if the list is empty 
};

#endif
