#ifndef PRODUCTCOLLECTION_H
#define PRODUCTCOLLECTION_H
#include "collectiontree.h"
#include "event.h"
#include "classic.h"
#include "comedy.h"	//not sure about this include, but using it temporarily
#include "drama.h"
#include "error.h"
#include <sstream>

const int A_INDEX = 65; //memory index of capital A (used for dealing with geners)
//#include <string>


/* 
The ProductCollection function will collect information about the product and
insert the data into a linked list. This class has basic linked list function
insert, retrieve, and print 
*/

class ProductCollection{
public:
	ProductCollection(); //default constractor
	virtual ~ProductCollection(); //default destructor 
	
	//goes through ListNode linked list, comparing each Node's dataType() 
	//to the inserted Product's dataType() and inseting when it finds a match.
	//(this means product type and genre must match.) if no match is found, a new
	//ListNode is created and the Product is inserted into its tree.
	Error insert(Product *,std::string); //inset product into a linked list 
	Error retrieve(Product *,std::string); //retrieve product from a linked list 
	Error displayAll() const; //display all the products 
	bool isEmpty() const; //check if the list is empty 
	Error makeTransaction(Event*);
private:
	BinTree collectTree[26];
	Error displayDataTypes(const BinTree &) const;
	bool validGenre(std::string) const; //check if a genre is valid
	Error productSearch(Event*);
};
#endif
