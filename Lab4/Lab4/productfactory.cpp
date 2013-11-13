#ifndef PRODUCTFACTORY_H
#define PRODUCTFACTORY_H
#include "productfactory.h"
#include "product.h"
#include "movie.h"
#include <fstream>
#include <string>


class ProductFactory
{
private:
	Product* productTemplates[];
public:
	ProductFactory();
	virtual ~ProductFactory();
	Product *createProduct(std::string,ifstream&);	//parses input to create movies
	Product *createProduct(const Movie& m);		//used in place of a copy constructor for Product
};

#endif
