#include "productcollection.h"
#include <sstream>

//default constructor
ProductCollection::ProductCollection(){
    collectionSize = 0;
}

//default destructor 
ProductCollection::~ProductCollection(){} 

//goes through ListNode linked list, comparing each Node's dataType() 
//to the inserted Product's dataType() and inseting when it finds a match.
//(this means product type and genre must match.) if no match is found, a new
//ListNode is created and the Product is inserted into its tree.
Error ProductCollection::insert(Product* pdtPtr){ 
    if(pdtPtr == NULL){
        return Error("Error: Product inserted is null.");
    }
    collectionSize++;
    char genre = pdtPtr->getKey();
    int genreIndex = genre - 65; // convert char to 1-26 int
    if(collection[genreIndex].insert(pdtPtr)){
        return Error();  
    }
    delete pdtPtr;
    return Error("Error: Could not insert product.");        
}  

//retrieve product from a linked list 
Error ProductCollection::retrieve(Product* pdtPtr){ //TODO rename retrieve() to productExists()
    char genre = pdtPtr->getKey();
    int genreIndex = genre - 65; // convert char to 1-26 int
    if(collection[genreIndex].retrieve(pdtPtr)){ 
        return Error();  
    } 
    return Error("Error: Unable to find product.");
} 

//display all the products 
Error ProductCollection::displayAll() const{ //TODO: REWRITE
    for(int i = 0; i < 26; ++i){
        if(!collection[i].isEmpty()){
            std::cout << collection[i].getName() << std::endl;
            std::cout << "*IN* *OUT*" << std::endl;
            Error e = displayDataTypes(collection[i]);
            if(e.getErrorMessage() != ""){
                return Error();  
            } 
            std::cout << collection[i] << std::endl;
        } 
    }
    return Error();
} 

 //check if the list is empty 
bool ProductCollection::isEmpty() const{
    bool ret = false;
    for(int i = 0; i < 26; ++i){
        if(!collection[i].isEmpty()){
            ret = true;
        }
    }
    return ret;
}

std::string ProductCollection::search(std::string target){
    std::string ret = "";
    std::vector<std::string> parsedSearch;
    std::string token, cmdChar, custID, format, genre;
    std::istringstream ss(target);
    ss >> cmdChar;
    ss >> custID;
    ss >> format;
    ss >> genre;

    Classic classic;
    Comedy comedy;
    Drama drama;

    switch (genre.at(0))  //I know this is bad, but I'm in a hurry
    {
    case 'C': parsedSearch = classic.parseCommand(target);
        break;
    case 'D': parsedSearch = drama.parseCommand(target);
        break;
    case 'F': parsedSearch = comedy.parseCommand(target);
        break;
    default: std::cout << "Error: Genre does not exist" << std::endl;
        return "";
    }

   for(int i = 0; i < 26; ++i){ //Position in productcollection array
        if(!collection[i].isEmpty()){
            std::vector<std::string> sortedBy = collection[i].getSortedBy();
            for(int k = 0; k < sortedBy.size() && k < parsedSearch.size(); ++k){
                //compare sortedby vector with comma parsed target string vector
                std::string productData = collection[i].getProductData(sortedBy.at(k));
                if(parsedSearch.at(k) == productData){
                    // return full string
                    std::vector<std::string> dataTypes = collection[i].getDataTypes();
                    for(int p = 0; p < dataTypes.size(); ++p){
                        ret.append(dataTypes.at(p));
                    }
                }
            }
        } 
    }
    if(ret == ""){
        std::cout << "Product not found." << std::endl;
    }
    return ret;
}


Error ProductCollection::displayDataTypes(const BinTree& dataTree) const{ //TODO: REWRITE
    std::vector<std::string> dataTypes = dataTree.getDataTypes();
    int getDataTypeSize = dataTree.getDataTypeSize();
    std::cout << "DVD  DVD ";
    for(int i = 0; i < getDataTypeSize; i++){
        std::string tmpType = dataTypes.at(i);
        tmpType.resize(Product::maxDataLength,' '); //TODO: NOT SURE IF NECESSARY
        std::cout << tmpType;
    }
    std::cout << std::endl;
    return Error();
}