#pragma once
#ifndef PRODUCTFORMATCOLLECTION_H
#define PRODUCTFORMATCOLLECTION_H
#define DEFAULT_PRODUCT_QUANTITY 10;
#define DEFAULT_PRODUCT_SIZE 100;
#include "productformat.h"
#include <string>
#include <list>

/*
Contains quantites and max quantites of various ProductFormats in a collection.
*/
class ProductFormatCollection{
private:
	struct FormatAmount
	{
		ProductFormat* format;
		int count; // Number in stock
	    int size;  // Number of products in total
        // size - count = number of products being rented
	};
	std::list<FormatAmount*> formatDataList;
	void addQuantity(FormatAmount*, int);

		
public:
    ProductFormatCollection();
    virtual ~ProductFormatCollection();
    //Returns the amount of items that particular ProductFormat has.
	int getFormatAmount(ProductFormat*)const; 
	int getFormatMaxAmount(ProductFormat*);
    std::string getFormatNames();  //iterate, display productformats //TODO: possibly use this instead of product::validFormatNames()
	void addProductFormat(ProductFormat);
	void addProductFormat(ProductFormat, int, int);
	void incrProductQuantity(std::string);

};

#endif
