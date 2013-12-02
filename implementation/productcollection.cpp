#include "productcollection.h"

 //default constructor
ProductCollection::ProductCollection(){}

//default destructor 
ProductCollection::~ProductCollection(){} 

//goes through ListNode linked list, comparing each Node's dataType() 
//to the inserted Product's dataType() and inseting when it finds a match.
//(this means product type and genre must match.) if no match is found, a new
//ListNode is created and the Product is inserted into its tree.
Error ProductCollection::insert(Product* pdtPtr){ 
    std::string genre = pdtPtr->getKey();
    int genreIndex = (int) genre[0] - A_INDEX;
    if(trees[genreIndex].insert(pdtPtr)){
        return Error();  
    } 
    return Error("Error: Could not insert product.");
}  

//retrieve product from a linked list 
Error ProductCollection::retrieve(Product* pdtPtr){
    std::string genre = pdtPtr->getKey();
    int genreIndex = (int) genre[0] - A_INDEX;
    if(trees[genreIndex].retrieve(pdtPtr)){
        return Error();  
    } 
    return Error("Error: Unable to find product.");
} 

//display all the products 
Error ProductCollection::displayAll() const{ 
    int collectionSize = sizeof(trees)/sizeof(*trees);
    Error empty;
    for(int i = 0; i < collectionSize; i++){
        if(!trees[i].isEmpty()){
            //TODO: show genre and type here
            std::cout << trees[i].getKey() << std::endl;
            empty = displayDataTypes(trees[i]);        //should this be an error?
            std::cout << std::endl << 
"------------------------------------------------------------------------------" 
            << std::endl;
            if(empty.getErrorMessage() != ""){
                return Error();  
            } 
            std::cout << trees[i] << std::endl;
        } 
    }
    return Error(""); //TODO: Needs a message    
} 

 //check if the list is empty 
bool ProductCollection::isEmpty() const{
    //TODO
    return true;
}


Error ProductCollection::displayDataTypes(const BinTree& dataTree) const{
    Error empty;
    const std::string* dataTypes = dataTree.dataTypeNames();
    int dataTypeCount = dataTree.dataTypeCount();
    for(int i = 0; i < dataTypeCount; i++){
        std::string nextType = dataTypes[i];
        nextType.resize(MAX_DATA_LENGTH,' ');
        std::cout << nextType;
    }
    return empty;
}