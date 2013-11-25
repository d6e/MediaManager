#include "productfactory.h"

ProductFactory::ProductFactory(){
	//IDEA: may need a special, instantiable "blankMovie" type to solve this problem.

	int comedyIndex = hash("F");
	productTemplates[comedyIndex] = new Comedy();

	int dramaIndex = hash("D");
	productTemplates[dramaIndex] = new Drama(); 

	//TODO: fills producttemplates with instances of each instantiatable 
    //Product object, using pcollect and hash fuction.
}

Product* ProductFactory::create(std::string key){
	int index = hash(key);
	return productTemplates[index]; //TODO: error checking (maybe not here though)
}

int ProductFactory::hash(std::string key){
	return (int)(key[0]);	//currently casts the first letter to a number. (A -> 1, B -> 2, etc)
}

/*
ProductFactory::ProductFactory(ProductCollection){
	//TODO: fills producttemplates with instances of each instantiatable 
    //Product object
}
*/