#include "product.h"

Product::Product(){}

Product::~Product(){}

// Returns false if input invalid.
bool Product::setData(Event* e){
    return true;
}

//increments the quantity of a particular product format.
void Product::incrementQuantity(ProductFormat){

}		

//number of copies borrowed by customers of a particular product format
int Product::getBorrowedItems(ProductFormat) const{
	return 0; //TODO
} 			

//number of copies borrowed by customers of a particular product format
int Product::getRemainingItems(ProductFormat) const{
	return 0; //TODO

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