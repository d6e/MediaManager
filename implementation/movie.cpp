#include "movie.h"

const std::string Movie::formats[] = {"DVD"}; 

Movie::~Movie(){}

// Inits to DVD for now.
void Movie::initValidFormats(){
    std::string format = "D";
    ProductFormat pf(format);
}

const std::string* Movie::validFormatNames() const{
    return formats;
}

const int Movie::validFormatCount() const{  //TODO: REWRITE
        return sizeof(formats)/sizeof(*formats);
}