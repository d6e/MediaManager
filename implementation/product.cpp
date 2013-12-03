#include "product.h"
#include <iostream>

Product::Product(){}

Product::~Product(){}

// Returns false if input invalid.
bool Product::setData(Event* e){
    return true;
}

void Product::display(std::ostream& output) const{  //TODO: REWRITE
        const std::string* tempTypeNames = dataTypeNames();
        const int dataTypeSize = getDataTypeSize();
        for(int i = 0; i < dataTypeSize; i++){
                    std::string nextData = getData(tempTypeNames[i]);
                    normalizeLength(nextData);
                    output << nextData;
        }
        output << std::endl;
        displayFormatCollection(output);
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

void Product::normalizeLength(std::string& data) const{ //TODO:REWRITE
        if(data.length() > MAX_DATA_LENGTH*1) truncate(data);        //the *1 is necessary to avoid a waring from the compiler
        else data.resize(MAX_DATA_LENGTH, ' ');
}

void Product::truncate(std::string& longString) const{  //TODO: rewrite
        longString.resize(MAX_DATA_LENGTH - 3);
        longString.resize(MAX_DATA_LENGTH, '.');
}

void Product::displayFormatCollection(std::ostream& output) const{        //TODO: rewrite
        const std::vector<std::string> formatNames = getFormatNames();
        for(int i = 0; i < formatNames.size(); i++){
                const std::string formatKey = formatNames.at(i);
                ProductFormat* p = getProductFormat(formatKey);
                output << formatKey << ": " << inventory.getFormatAmount(p) << " ";
        }
        output << std::endl;
}

ProductFormat* Product::getProductFormat(std::string key) const{ 
    std::map<std::string,ProductFormat*>::const_iterator index = validFormats.find(key);
    ProductFormat* data = index -> second; //TODO: data is always NULL
    return data;
}

// The addData() method inserts data into the Product's hashtable, with the form
// <dataType,data> (Example: <"title","Titanic">). This data is retrieved in a
// similar way by dataString().
bool Product::addData(std::string key,std::string value){
	productData[key] = value;
	return true; //TODO
}

//Returns false if data invalid.
bool Product::addFormat(ProductFormat){
	return true; //TODO

}

//upon receiving a duplicate product, add 10 to the quantity of the existing product's default format.
void Product::duplicate(NodeData* n){      //TODO:rewrite  
    const Product* p = static_cast<const Product*>(n);
    const std::vector<std::string> formatNames = p->getFormatNames();
    // const std::string defaultFormat = formatNames[0];
    const std::string defaultFormat = formatNames.at(0);//TODO: not sure if correct
    //ProductFormat* pf = new ProductFormat(defaultFormat);
    inventory.duplicate(defaultFormat);
    //addFormat(pf);
    //delete pf;
}  

