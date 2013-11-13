#ifndef PRODUCTFACTORY_H
#define PRODUCTFACTORY_H
#include "product.h"
#include <string>

class ProductFactory
{
public:
    ProductFactory(ProductCollection);    //fills producttemplates with instances of each instantiatable Product object
    ~ProductFactory();
    Product *create(std::string key); //parses input to create Product objects, returns null if invalid hash key
	
private:
    ProductCollection pCollect;
	const int HASH_TABLE_SIZE = 256;
	Product* hashTable; // A pointer to an array of Products implemented as a hash table
	int hash(string key);
	
};
