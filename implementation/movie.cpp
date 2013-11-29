#include "movie.h"


Movie::~Movie(){}

// Inits to DVD for now.
void Movie::initValidFormats(){
    // ProductFormat* pf = new ProductFormat("D");
    std::string format = "D";
    ProductFormat pf(format);
    // validFormats[format] = pf; 
}

//TODO: clean up memory