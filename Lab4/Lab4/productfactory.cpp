#include "productfactory.h"


class ProductFactory
{
private:
	Product* productTemplates[];
public:
	ProductFactory();
	~ProductFactory();
	Product *createProduct(string,ifstream&);	//parses input to create movies
	Product *createProduct(const Movie& m);		//used in place of a copy constructor for Product
};