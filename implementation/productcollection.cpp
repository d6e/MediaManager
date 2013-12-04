#include "productcollection.h"

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
Error ProductCollection::retrieve(Product* pdtPtr){
    char genre = pdtPtr->getKey();
    int genreIndex = genre - 65; // convert char to 1-26 int
    if(collection[genreIndex].retrieve(pdtPtr)){ //TODO rename retrieve() to productExists()
        return Error();  
    } 
    return Error("Error: Unable to find product.");
} 

//display all the products 
Error ProductCollection::displayAll() const{ //TODO: REWRITE
    for(int i = 0; i < 26; ++i){
        if(!collection[i].isEmpty()){
            //TODO: show genre and type here
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


Error ProductCollection::displayDataTypes(const BinTree& dataTree) const{ //TODO: REWRITE
    Error empty;
    std::vector<std::string> dataTypes = dataTree.getDataTypes();
    int getDataTypeSize = dataTree.getDataTypeSize();
    std::cout << "DVD  DVD ";
    for(int i = 0; i < getDataTypeSize; i++){
        std::string tmpType = dataTypes.at(i);
        tmpType.resize(Product::maxDataLength,' '); //TODO: NOT SURE IF NECESSARY
        std::cout << tmpType;
    }
    std::cout << std::endl;
    return empty;
}