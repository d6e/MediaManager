#ifndef PRODUCTFACTORY_H
#define PRODUCTFACTORY_H
#include "productfactory.h"
#include "product.h"
#include "movie.h"
#include <string>


class ProductFactory
{
public:
	ProductFactory();
	virtual ~ProductFactory();
	Product *createProduct(std::string);	//parses input to create movies
private:
	static const int HASH_TABLE_SIZE = 256;
	Product* hashTable; // A pointer to an array of Product implemented as a hash table
	int hash(std::string key);
};

#endif
