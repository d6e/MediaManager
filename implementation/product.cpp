#include "product.h"
#include <iostream>

Product::Product(){
    // std::cout << "Created: " << std::endl;
}

Product::~Product(){
    // std::cout << "Destroyed: " << productData["TITLE"] << std::endl;
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
    std::string inStatus = "09";
    std::string outStatus = "08";
    format(inStatus, maxQuantityLength);
    format(outStatus, maxQuantityLength);
    std::cout << inStatus << " " << outStatus;

    std::vector<std::string> dataTypes = getDataTypes();
    for(int i = 0; i < getDataTypeSize(); ++i){
        std::string data = getData(dataTypes.at(i));
        format(data, maxDataLength);
        out << data;
    }
    displayProductFormatColl(out); //TODO: expand
}

void Product::format(std::string& data, int maxLength) const{
    if(data.length() > maxLength){
        data.resize(maxDataLength - 1);
        data.resize(maxDataLength, ' ');
    }
    else{
        data.resize(maxLength, ' ');  //creates buffer for display
    } 
}

std::string Product::getProductData(){
    std::string ret;
    std::vector<std::string> dataTypes = getDataTypes();
    for(int i = 0; i < getDataTypeSize(); ++i){
        std::string data = getData(dataTypes.at(i));
        format(data, maxDataLength);
        ret.append(data);
    }
    return ret;
}

//returns product data corresponding to key from hashmap
std::string Product::getProductData(std::string key){
    return getData(key);
}

void Product::displayProductFormatColl(std::ostream& out) const{ 
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
// <dataType,data> (Example: <"TITLE","Titanic">). This data is retrieved in a
// similar way by dataString().
void Product::addData(std::string key,std::string value){
	productData[key] = value;
}

 //adds product to productformatcollection
void Product::addFormat(ProductFormat* pf){
    pfc.addProductFormat(pf);
}

//upon receiving a duplicate product, add 10 to the quantity of the existing product's default format.
void Product::incrProductQuantity(NodeData* node){   
    Product* pdtPtr = static_cast<Product*>(node);
    std::vector<std::string> formatNames = pdtPtr->getFormatNames();
    pfc.incrProductQuantity(formatNames.at(0));
}  

