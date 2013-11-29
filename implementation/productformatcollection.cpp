#include "productformatcollection.h"


ProductFormatCollection::~ProductFormatCollection(){
    for(it = formatDataList.begin(); it != formatDataList.end(); ++it){
        // delete (*it)->format;
        delete *it;
    }
    formatDataList.clear();
}

int ProductFormatCollection::getFormatAmount(const ProductFormat* pfPtr) {
    for(it = formatDataList.begin(); it != formatDataList.end(); ++it){
        if((*it)->format->getName() == pfPtr->getName()){ //find corresponding pf
            return (*it)->count;
        }
    }   
    return -1; // get amount failed
}

int ProductFormatCollection::getFormatMaxAmount(const ProductFormat* pfPtr) {
    for(it = formatDataList.begin(); it != formatDataList.end(); ++it){
        if((*it)->format->getName() == pfPtr->getName()){ //find corresponding pf
            return (*it)->size;
        }
    }   
    return -1; // get amount failed
}

void ProductFormatCollection::addProductFormat(ProductFormat pf){
    FormatAmount* fa = new FormatAmount();
    fa->format = &pf;
    fa->count = DEFAULT_PRODUCT_QUANTITY;
    fa->size = DEFAULT_PRODUCT_SIZE;
    formatDataList.push_back(fa);
}

//iterate, display productformats
std::string ProductFormatCollection::getFormatNames(){
    std::string retVal = "";
    for(it = formatDataList.begin(); it != formatDataList.end(); ++it){
        retVal += " " + (*it)->format->getName();
    }
    return retVal;
}
