#include "product.h"
#include <iostream>

Product::Product(){}

Product::~Product(){}

// Returns false if input invalid.
bool Product::setData(Event* e){
    return true;
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
    std::vector<std::string> formatNames = getFormatNames();
    for(int i = 0; i < formatNames.size(); i++){
        ProductFormat* pf = getProductFormat(formatNames.at(i));
    }
    out << std::endl;
}

//formats the data properly for output
void Product::format(std::string& data, int maxLength) const{
    if(data.length() > maxLength){
        data.resize(maxDataLength - 1);
        data.resize(maxDataLength, ' ');
    }
    else{
        data.resize(maxLength, ' ');  //creates buffer for display
    } 
}

//accessor for product formats
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

