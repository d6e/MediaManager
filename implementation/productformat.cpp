#include "productformat.h"

// constructor
ProductFormat::ProductFormat(std::string name){
    formatName = name;
}

 // returns the private formatname string
std::string ProductFormat::getName() const{
    return formatName;
}

//Checks if two ProductFormats are equivilent
bool ProductFormat::equals(const ProductFormat pf){
    return (formatName == pf.getName());
}