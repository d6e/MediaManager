#ifndef MEDIAFACTORY_H
#define MEDIAFACTORY_H
#include "product.h"
#include <string>

class ProductFactory
{
public:
    ProductFactory();    //fills producttemplates with instances of each instantiatable Product object
    ~ProductFactory();
    Product *createProduct(std::string arg); //parses input to create Product objects
private:
	const std::string[] GENRE_CODES = {"F","C","D"};
	const std::string[] MEDIUM_CODES = {"D"};
	const int GENRE_AMOUNT = 3; 	
	
	bool createComedy(Product*&, std::string); // mItem doesn't point to anything unless return true
	bool createDrama(Product*&, std::string); // mItem doesn't point to anything unless return true
	bool createClassic(Product*&, std::string); // mItem doesn't point to anything unless return true
	
	
};
