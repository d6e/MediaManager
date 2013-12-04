#include "movie.h"

Movie::Movie(){
	formatList.push_back("DVD"); //load the name for each format here

	initValidFormats();
    // pfc.addProductFormat(pf); //populate the productformatcollection
	
}

Movie::~Movie(){}

// Inits to DVD for now.
void Movie::initValidFormats(){ //add all valid formats to the validformat map
	for(int i = 0; i < formatList.size(); ++i){
		std::string format = formatList.at(i);
	    ProductFormat pf(format);
	    validFormats[format] = &pf;		
	}
}

std::vector<std::string> Movie::getFormatNames() const{ 
    return formatList;
}
