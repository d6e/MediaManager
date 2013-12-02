#include "productformatcollection.h"


ProductFormatCollection::~ProductFormatCollection(){
    for(std::list<FormatAmount*>::const_iterator it = formatDataList.begin(); it != formatDataList.end(); ++it){
        // delete (*it)->format;
        delete *it;
    }
    formatDataList.clear();
}

int ProductFormatCollection::getFormatAmount(ProductFormat pf)const{
    ProductFormat* pfPtr = &pf;
    for(std::list<FormatAmount*>::const_iterator it = formatDataList.begin(); it != formatDataList.end(); ++it){
        if((*it)->format->getName() == pfPtr->getName()){//find corresponding pf
            return (*it)->count;
        }
    }   
    return -1; // get amount failed
}

int ProductFormatCollection::getFormatMaxAmount(const ProductFormat* pfPtr) {
    for(std::list<FormatAmount*>::const_iterator it = formatDataList.begin(); it != formatDataList.end(); ++it){
        if((*it)->format->getName() == pfPtr->getName()){//find corresponding pf
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
    for(std::list<FormatAmount*>::const_iterator it = formatDataList.begin(); it != formatDataList.end(); ++it){
        retVal += " " + (*it)->format->getName();
    }
    return retVal;
}

void ProductFormatCollection::duplicate(std::string searchName){ //TODO:REWRITE
        std::list<FormatAmount*>::iterator it=formatDataList.begin();
        while(it != formatDataList.end()){
                if((*it) -> format -> getName() == searchName){
                        FormatAmount& fa = **it;
                        int amount = DEFAULT_PRODUCT_QUANTITY;
                        addAmount(fa, amount);
                        return;
                }
                ++it;
        } 
}

void ProductFormatCollection::addAmount(FormatAmount& format, int amount){ //TODO: rewrite
    format.size += amount;
    format.count += amount;
}
