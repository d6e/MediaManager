#pragma once
#ifndef MOVIE_H
#define MOVIE_H
#include "product.h"
#include "productformat.h"
#include <string>
#include <map>

/*
Contains the attributes of a Movie. Valid formats of Movies are initialized 
here.
*/
class Movie : public Product 
{
public:
    virtual ~Movie();
private:
	virtual void initValidFormats(); // Inits to DVD for now.
};

#endif