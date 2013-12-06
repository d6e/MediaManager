#pragma once
#ifndef MOVIE_H
#define MOVIE_H
#include "product.h"
#include "productformat.h"
#include <string>
#include <vector>

/*
Contains the attributes of a Movie. Valid formats of Movies are initialized 
here.
*/
class Movie : public Product 
{
public:
    Movie();
    virtual ~Movie();
private:
	std::vector<std::string> formatList;
	virtual void initValidFormats(); // Inits to DVD for now.
	virtual std::vector<std::string> getFormatNames() const;
};

#endif