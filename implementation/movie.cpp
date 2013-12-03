#include "movie.h"

Movie::Movie(){
	formatList.push_back("DVD");

	for(int i = 0; i < formatList.size(); ++i){
	    inventory.addProductFormat(ProductFormat(formatList.at(i)));
	}
}
Movie::~Movie(){}

// Inits to DVD for now.
void Movie::initValidFormats(){
	ProductFormat* pf;
	for(int i = 0; i < formatList.size(); ++i){
		std::string format = "DVD";
		// std::string format = formatList.at(i);
	    pf = new ProductFormat(format);
	    validFormats[format] = pf;		
	}
    pf = NULL;	
}

const std::vector<std::string> Movie::getFormatNames() const{ 
    return formatList;
}
