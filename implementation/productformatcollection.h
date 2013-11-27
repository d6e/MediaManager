#ifndef PRODUCTFORMATCOLLECTION_H
#define PRODUCTFORMATCOLLECTION_H
#define DEFAULT_PRODUCT_QUANTITY 10;  //TODO: verify that this represents count
#define DEFAULT_PRODUCT_SIZE 100;
#include "productformat.h"
#include <string>
#include <list>

/*
Contains quantites and max quantites of various ProductFormats in a collection.
*/
class ProductFormatCollection{
public:
	ProductFormatCollection();
    //Returns the amount of items that particular ProductFormat has.
	int getFormatAmount(const ProductFormat*) const; 
	int getFormatMaxAmount(const ProductFormat*) const;
	
	bool addProductFormat(ProductFormat);
private:
	struct FormatAmount
	{
		ProductFormat* format;
		int count; // Number in stock
	    int size;  // Number of products in total
        // size - count = number of products being rented
	};
		
    std::list<FormatAmount*>::const_iterator it;
	std::list<FormatAmount*> formatDataList;
};

#endif
