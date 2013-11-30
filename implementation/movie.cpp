#include "movie.h"

Movie::Movie(){initValidFormats();}

const std::string* Movie::validFormatNames() const{
	//cout << "THIS IS A MOVIE" << endl;
	return MOVIE_FORMATS;
}

const int Movie::validFormatCount() const{
	return sizeof(MOVIE_FORMATS)/sizeof(*MOVIE_FORMATS);
}