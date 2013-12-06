#pragma once
#ifndef PRODUCTCOLLECTION_H
#define PRODUCTCOLLECTION_H
#include "error.h"
#include "product.h"
#include "bintree.h"
#include "productcollection.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"
#include <string>

/* 
The ProductCollection function will collect information about the product and
insert the data into a linked list. This class has basic linked list function
insert, retrieve, and print 
*/

class ProductCollection{
	/* overwrite the << operator */
	friend std::ostream & operator<<(std::ostream &, const ProductCollection &);
    
private:
    BinTree collection[26];
    Error displayDataTypes(const BinTree &) const; //TODO: REWRITE
    int collectionSize; //number of nodes in the collection
public:
	ProductCollection(); //default constractor
	virtual ~ProductCollection(); //default destructor 
	//goes through ListNode linked list, comparing each Node's dataType() 
	//to the inserted Product's dataType() and inseting when it finds a match.
	//(this means product type and genre must match.) if no match is found, a new
	//ListNode is created and the Product is inserted into its tree.
	Error insert(Product *); //inset product into a linked list 
	Error retrieve(Product *); //retrieve product from a linked list 
	std::string search(std::string); //searches for product
	Error displayAll() const; //display all the products 
	bool isEmpty() const; //check if the list is empty 
};

#endif
