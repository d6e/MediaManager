#include "movie.h"

Movie::Movie(){
	formatList.push_back("DVD"); //load the name for each format here

	initValidFormats();
}
Movie::~Movie(){}

// Inits to DVD for now.
void Movie::initValidFormats(){
	for(int i = 0; i < formatList.size(); ++i){
		std::string format = formatList.at(i);
	    ProductFormat pf(format);
	    validFormats[format] = &pf;		
	}
}

const std::vector<std::string> Movie::getFormatNames() const{ 
    return formatList;
}
