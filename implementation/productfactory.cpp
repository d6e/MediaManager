#include "productfactory.h"
#include <sstream>

ProductFactory::ProductFactory(ProductCollection* pC) 
        : HASH_TABLE_SIZE(256) {
    pCollect = pC;    

    products['F'] = new Comedy();
    products['D'] = new Drama();
    products['C'] = new Classic();
}

ProductFactory::~ProductFactory(){
    for(it = products.begin(); it != products.end(); ++it) {
        if(it->second != NULL){
            delete it->second;
            it->second = NULL;
        }
    }
} 

//parses input to create Product objects, returns null if invalid hash key
Product* ProductFactory::create(std::string key){
    std::string pdtString;
    std::string restOfString;
    std::stringstream ss;
    ss << key;
    ss >> pdtString;
    restOfString = ss.str();
    char pdtChar = pdtString.at(0); //Convert string to a char

    Product* pdtPtr = NULL;
    if(products[pdtChar] != NULL){
        pdtPtr = products[pdtChar]->create(); //get product pointer from hashtable 
        pdtPtr->setData(new Event(restOfString));    
    }
    return pdtPtr;
}

