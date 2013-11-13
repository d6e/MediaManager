#ifndef MOVIE_H
#define MOVIE_H
#include "product.h"
#include <string>

/*
Contains the attributes of a Movie. Valid formats of Movies are initialized here.
*/
class Movie : public Product 
{
private:
	virtual initValidFormats(); // Inits to DVD for now.
};
