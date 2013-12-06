#pragma once
#ifndef PRODUCT_H
#define PRODUCT_H
#include "hashtable.h"
#include <string>
#include "event.h"
#include "productformat.h"
#include "nodedata.h"
#include "productformatcollection.h"
#include <map>
#include <iostream>

/*
A product object is a movie, a book, a music album, or some other form of 
product. At its most basic level, a Product has the ability to say which of 
these types it is and/or what genre it is, store and output its data (which 
might include title, publication date, composer, sculptor, set designer, etc), 
and compare itself to other Product objects of the same type and genre. 
*/

class Product : public NodeData {
public:
	Product();
	virtual ~Product();
	virtual bool setData(Event*); // Returns false if input invalid.
    virtual Product* create() = 0; // Creates a new, empty Product 
	virtual void incrProductQuantity(NodeData*);
	
	// Returns all data, inorder of input, deliminated by commas
	virtual std::vector<std::string> getDataTypes() const = 0; 
	// Returns the sorting data, delineated by commas
	virtual std::vector<std::string> getSortedBy() const = 0; 
    virtual int getDataTypeSize() const = 0; // returns size of DataTypes
    virtual int getSortedBySize() const = 0; // returns size of SortedBy
	
	//comparison operators compare product by their sorting criteria
	virtual bool operator==(const NodeData&) const = 0;
    virtual bool operator!=(const NodeData&) const = 0;
    virtual bool operator<(const NodeData&) const = 0;
    virtual bool operator>(const NodeData&) const = 0;
    virtual bool operator<=(const NodeData&) const = 0;
    virtual bool operator>=(const NodeData&) const = 0;

	virtual void display(std::ostream&) const; // Displays contents via cout

    //returns the type (the class) of product. Used as a key.
	virtual std::string getName() const = 0;
	virtual char getKey() const = 0;
	virtual std::string getData(std::string key) const = 0;

	const static int maxDataLength = 20;    //special length for data
	const static int maxQuantityLength = 4; //special length for quantities
protected:
    //Contains valid formats of the product. The identifier code is the key. 
    std::map<std::string,ProductFormat*> validFormats; 

	//Contains the attributes of this product.
	std::map<std::string,std::string> productData;  

	//Contains the quantities and different formats this product has.	
	ProductFormatCollection pfc; 
private:
	//Formats data for output
	void format(std::string&, int) const;

	//accessor for productformats
	ProductFormat* getProductFormat(std::string) const;

	// Returns false if key doesn't exist  in productData;
    void addData(std::string key,std::string value); 
	void addFormat(ProductFormat*); //adds product to productformatcollection

    // All products must have possible format(s).        
	virtual void initValidFormats() = 0; 
  	virtual std::vector<std::string> getFormatNames() const = 0;

};

#endif