#ifndef PRODUCTFACTORY_H
#define PRODUCTFACTORY_H
#include "product.h"
#include <string>

/*
The class ProductFactory collects information about the movie { Classic, 
Drama, Comedy } Once the input has been parsed, this class will fills product 
templates with instances of each instantiatable product object. It will then 
create the product objects , returns null if there is an invalid hash key

*/
class ProductFactory
{
public:
    //fills producttemplates with instances of each instantiatable 
    //Product object
    ProductFactory(ProductCollection);    
    virtual ~ProductFactory();
    //parses input to create Product objects, returns null if invalid hash key
    Product *create(std::string key); 
	
private:
    ProductCollection pCollect;
	const int HASH_TABLE_SIZE = 256; //create a hash table with the size of 256
    // A pointer to an array of Products implemented as a hash table
	Product* hashTable; 
	int hash(std::string key); //find the given key in the hash table 
	
};

#endif
