#include "productcollection.h"

 //default constructor
ProductCollection::ProductCollection(){
    collectTree = new CollectionTree();
    treeNode = new BinTree[27];
}

//default destructor 
ProductCollection::~ProductCollection(){
    delete collectTree;
    delete[] treeNode;
    collectTree = NULL;
    treeNode = NULL;
} 

//goes through ListNode linked list, comparing each Node's dataType() 
//to the inserted Product's dataType() and inseting when it finds a match.
//(this means product type and genre must match.) if no match is found, a new
//ListNode is created and the Product is inserted into its tree.
Error ProductCollection::insert(Product *){ 
    //TODO
    return Error(""); 
}  

//retrieve product from a linked list 
Error ProductCollection::retrieve(Product *){
    //TODO
    return Error("");
} 

//display all the products 
Error ProductCollection::displayAll() const{
    //TODO
    return Error("");
} 

 //check if the list is empty 
bool ProductCollection::isEmpty() const{
    //TODO
    return true;
}