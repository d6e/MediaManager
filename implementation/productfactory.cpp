#include "productfactory.h"

ProductFactory::ProductFactory(){
	for(int i = 0; i < HASH_TABLE_SIZE; i++){
		productTemplates[i] = NULL;
	}
	
	int classicIndex = hash("C");
	productTemplates[classicIndex] = new Classic();
	
	int dramaIndex = hash("D");
	productTemplates[dramaIndex] = new Drama(); 

	int comedyIndex = hash("F");
	productTemplates[comedyIndex] = new Comedy();
}

Product* ProductFactory::create(std::string key){
	int index = hash(key);
	if(productTemplates[index] != NULL){
		return productTemplates[index] -> create(); //TODO: error checking (maybe not here though)
	}
	return NULL;
}

int ProductFactory::hash(std::string key){
	return (int)(key[0]);	//currently casts the first letter to a number. (A -> 1, B -> 2, etc)
}