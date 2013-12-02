#ifndef PRODUCTFORMATCOLLECTION_H
#define PRODUCTFORMATCOLLECTION_H
#define DEFAULT_PRODUCT_QUANTITY 10;
#define MAX_FORMAT_STRING_LENGTH 20;
#include "productformat.h"
#include <string>
#include <list>
#include <algorithm>
#include <fstream>
#include <iostream> 

/*
Contains quantites and max quantites of various ProductFormats in a collection.
*/
class ProductFormatCollection{
public:
	//ProductFormatCollection();
    //Returns the amount of items that particular ProductFormat has.
	int getFormatAmount(const ProductFormat&) const; 
	int getFormatMaxAmount(const ProductFormat&) const;
	
	bool addProductFormat(ProductFormat*);
	const void display(std::ostream&) const;
private:
	struct FormatAmount
	{
		//void addQuantity(int);
		ProductFormat* format;
		int count;	//amount in stock
	    int size;	//total amount owned
	};
	void addAmount(FormatAmount &, int);
	std::list<FormatAmount> formatDataList;
};

#endif
