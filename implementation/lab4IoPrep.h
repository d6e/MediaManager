/*
#ifndef LAB4IOPREP_H
#define LAB4IOPREP_H

//#include "movie.h"
#include "moviefactory.cpp"
#include "bintree.h"
#include "moviecollection.h"
using namespace std;

#define INPUT_DELIMITER ", "
	//this array deals with strings, but the hashtable must  deal with objects.
const string VALID_GENRES[] = {"C","D","F"};	//TODO: structure this differently
//const ClassicMovie emptyClassic;
//const DramaMovie emptyDrama;
//const ComedyMovie emptyComedy;
//const Movie EMPTY_MOVIES[] = {emptyClassic,emptyDrama,emptyComedy};	//should this be a pointer array? (also it should definitely be in a Factory class)

class Lab4IoPrep{
public:
	Lab4IoPrep();
	void readInputFile(ifstream &);
	bool validGenre(string);
	void setUpGenreTable();
	//Movie emptyMovie(string);

	//map<string,Movie> genreTable;
};
#endif
*/