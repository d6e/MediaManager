
#ifndef MOVIE_H
#define MOVIE_H
#include "product.h"
const std::string MOVIE_FORMATS [] = {"DVD"}; 
class Movie : 
public Product {
public:
	Movie();
private:
    virtual const std::string* validFormatNames() const;
    virtual const int validFormatCount() const;
};

#endif