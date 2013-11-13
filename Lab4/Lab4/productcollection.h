#ifndef PRODUCTCOLLECTION_H
#define PRODUCTCOLLECTION_H
#include "error.h"
#include "product.h"
#include "collectiontree.h"
#include "productcollection.h"
#include <string>



class ProductCollection{
	friend ostream & operator<<(ostream &, const ProductCollection &);
public:
	ProductCollection();
	virtual ~ProductCollection();
	//goes through ListNode linked list, comparing each Node's dataType() 
	//to the inserted Product's dataType() and inseting when it finds a match.
	//(this means product type and genre must match.) if no match is found, a new
	//ListNode is created and the Product is inserted into its tree.
	Error insert(Product *);
	Error retrieve(Product *);
	Error displayAll() const;
	bool isEmpty() const;
private:
	CollectionTree* collectTree;
};
#endif