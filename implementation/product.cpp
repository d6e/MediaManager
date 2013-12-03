#include "product.h"
#include <iostream>

Product::Product(){}

Product::~Product(){}

// Returns false if input invalid.
bool Product::setData(Event* e){
    return true;
}

//increments the quantity of a particular product format.
void Product::incrementQuantity(ProductFormat){
//TODO
}		

//number of copies borrowed by customers of a particular product format
int Product::getBorrowedItems(ProductFormat) const{
	return 0; //TODO
} 			

//number of copies borrowed by customers of a particular product format
int Product::getRemainingItems(ProductFormat) const{
	return 0; //TODO

} 			

void Product::display(std::ostream& out) const{
    std::vector<std::string> dataTypes = getDataTypes();
    for(int i = 0; i < getDataTypeSize(); ++i){
        std::string data = getData(dataTypes.at(i));
        normalizeStringLength(data);
        out << data;
    }
    printProductFormatColl(out);
    out << std::endl;
}

//makes sure display doesn't take up too much space
void Product::normalizeStringLength(std::string& data) const{
    if(data.length() > maxDataLength){
        truncateData(data);
    }
    else{
        data.resize(maxDataLength, ' ');  
    } 
}

//truncates strings so they don't take up too much space
void Product::truncateData(std::string& data) const{
    data.resize(maxDataLength);
}

void Product::printProductFormatColl(std::ostream& out) const{ 
    std::vector<std::string> formatNames = getFormatNames();
    for(int i = 0; i < formatNames.size(); i++){
        ProductFormat* pf = getProductFormat(formatNames.at(i));
        out << formatNames.at(i) << ": " << pfc.getFormatAmount(pf) << " ";
    }
    out << std::endl;
}

ProductFormat* Product::getProductFormat(std::string key) const{ 
    std::map<std::string,ProductFormat*>::const_iterator index = validFormats.find(key);
    ProductFormat* data = index->second;
    return data;
}

// The addData() method inserts data into the Product's hashtable, with the form
// <dataType,data> (Example: <"title","Titanic">). This data is retrieved in a
// similar way by dataString().
void Product::addData(std::string key,std::string value){
	productData[key] = value;
}

 //adds product to productformatcollection
void Product::addFormat(ProductFormat pf){
    pfc.addProductFormat(pf);
}

//upon receiving a duplicate product, add 10 to the quantity of the existing product's default format.
void Product::incrProductQuantity(NodeData* node){      //TODO:rewrite  
    Product* pdtPtr = static_cast<Product*>(node);
    std::vector<std::string> formatNames = pdtPtr->getFormatNames();
    pfc.incrProductQuantity(formatNames.at(0));
}  

