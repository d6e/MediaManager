#include "productformat.h"

ProductFormat::ProductFormat(std::string name){
	formatName = name;
}

std::string ProductFormat::getName() const{
	return formatName;
}

bool ProductFormat::equals(const ProductFormat pf){
	return formatName == pf.formatName;
}