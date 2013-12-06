#include "productformatcollection.h"

ProductFormatCollection::ProductFormatCollection(): 
        productQuantity(10), productSize(100){} //init lists are more efficient

ProductFormatCollection::~ProductFormatCollection(){
    std::vector<FormatAmount*>::const_iterator it;
    for(it = formatDataList.begin(); it != formatDataList.end(); ++it){
        delete *it;
    }
    formatDataList.clear();
}

//returns the quantity from a formatAmount objects
int ProductFormatCollection::getFormatAmount(ProductFormat* pfPtr)const{
    std::vector<FormatAmount*>::const_iterator it;
    if(pfPtr != NULL){ 
        for(it = formatDataList.begin(); it != formatDataList.end(); ++it){
            std::string fname = (*it)->format->getName();
            if(fname == pfPtr->getName()){//find corresponding pfPtr
                return (*it)->quantity;
            }
        }    
    }
    return -1; // getFormatAmount failed
}

//returns the max stock from a formatAmount objects
int ProductFormatCollection::getFormatMaxAmount(ProductFormat* pfPtr) {
    std::vector<FormatAmount*>::const_iterator it;
    for(it = formatDataList.begin(); it != formatDataList.end(); ++it){
        if((*it)->format->getName() == pfPtr->getName()){//find matching pfPtr
            return (*it)->size;
        }
    }   
    return -1; // getFormatAmount  failed
}

//Inserts a productFormat object into the productformatcollection
void ProductFormatCollection::addProductFormat(ProductFormat* pfPtr){ 
    FormatAmount insrtFA;
    std::vector<FormatAmount*>::iterator it;
    for(it = formatDataList.begin(); it != formatDataList.end();++it){
        if((*it)->format->getName() == pfPtr->getName()){
            FormatAmount* format;
            format = *it;
            int quantity = productQuantity;
            format->size += quantity;
            format->quantity += quantity;
        }
    } 
    //set formatAmount's attributes
    insrtFA.size = productQuantity;
    insrtFA.quantity = productQuantity;
    insrtFA.format = pfPtr;
    FormatAmount* insrtPtr = &insrtFA;
    formatDataList.push_back(insrtPtr);
}

//iterates through the productformatcollection, returning the name of format
std::string ProductFormatCollection::getFormatNames(){
    std::string retVal = "";
    std::vector<FormatAmount*>::const_iterator it;
    for(it = formatDataList.begin(); it != formatDataList.end(); ++it){
        retVal += " " + (*it)->format->getName();
    }
    return retVal;
}

//increases the quantity of the product
void ProductFormatCollection::incrProductQuantity(std::string formatName){
    std::vector<FormatAmount*>::iterator it;
    for(it = formatDataList.begin(); it != formatDataList.end(); ++it){
        if((*it)->format->getName() == formatName){
            FormatAmount* format = *it;
            //increase by default quantity
            int quantity = productQuantity; 
            format->size += quantity;
            format->quantity += quantity;
        }
    } 
}

