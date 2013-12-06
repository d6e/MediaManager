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
    int genreIndex = pdtPtr->getKey() - 65; // convert char to 1-26 int
    if(collection[genreIndex].retrieve(pdtPtr)){ 
        return Error();  
    } 
    return Error("Error: Unable to find product.");
} 

//display all the products 
Error ProductCollection::displayAll() const{
    for(int i = 0; i < 26; ++i){ //collection is an array of 26
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

//displays the data types
Error ProductCollection::displayDataTypes(const BinTree& tree) const{
    std::vector<std::string> typesList = tree.getDataTypes();
    std::cout << "DVD  DVD ";
    for(int i = 0; i < tree.getDataTypes().size(); i++){
        typesList.at(i).resize(Product::maxDataLength,' '); 
        std::cout << typesList.at(i);
    }
    std::cout << std::endl;
    return Error();
}