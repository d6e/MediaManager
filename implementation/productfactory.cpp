#include "productfactory.h"
#include <sstream>

ProductFactory::ProductFactory(ProductCollection* pC) {
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
Product* ProductFactory::create(std::string data){
    Product* pdtPtr = NULL;
    if(data == ""){
        return pdtPtr;
    }
    std::string pdtString;
    std::string restOfString;
    std::stringstream ss;
    ss << data;
    ss >> pdtString;
    restOfString = ss.str();
    char pdtChar = pdtString.at(0); //Convert string to a char

    if(!keyExists(pdtChar)){
        return pdtPtr;
    }

    pdtPtr = products[pdtChar]->create(); //get product pointer from hashtable 
    pdtPtr->setData(new Event(restOfString));    
    return pdtPtr;
}

//Searches products for if a char corresponding to a command exists
bool ProductFactory::keyExists(char key){
    it = products.find(key);
    if (it == products.end()){
        return false;
    }
    else{
        return true;
    }
}