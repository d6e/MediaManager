#pragma once
#ifndef PRODUCTFORMATCOLLECTION_H
#define PRODUCTFORMATCOLLECTION_H
#include "productformat.h"
#include <string>
#include <vector>

/*
Contains quantites and max quantites of various ProductFormats in a collection.
*/
class ProductFormatCollection{
private:
	struct FormatAmount
	{
		ProductFormat* format;
		int quantity; // quantity of products
	    int size;  // total available products
        // size - quantity = number of products being rented
	};
	std::vector<FormatAmount*> formatDataList;
	int productQuantity; //initialized in constructor init list
	int productSize; //initialized in constructor init list
		
public:
    ProductFormatCollection();
    virtual ~ProductFormatCollection();
    //Returns the number of items a productformat may have
	int getFormatAmount(ProductFormat*)const; 
	int getFormatMaxAmount(ProductFormat*);
    std::string getFormatNames();  //accessor for productformat names //TODO: possibly use this instead of product::validFormatNames()
	void addProductFormat(ProductFormat*);
	// void addProductFormat(ProductFormat, int, int);
	void incrProductQuantity(std::string);

};

#endif
