#include "productformatcollection.h"

ProductFormatCollection::ProductFormatCollection(){
    FormatAmount fa();
    fa.count = DEFAULT_PRODUCT_QUANTITY;
    fa.size = DEFAULT_PRODUCT_SIZE;
    formatDataList.insert(fa); 
}

ProductFormatCollection::~ProductFormatCollection(){
}


int ProductFormatCollection::getFormatAmount(const ProductFormat* pfPtr) const{
}

int ProductFormatCollection::getFormatMaxAmount(const ProductFormat* pfPtr) const{
}

bool ProductFormatCollection::addProductFormat(ProductFormat pf){
    formatDataList.insert();
}