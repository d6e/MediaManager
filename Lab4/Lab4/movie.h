#ifndef MOVIE_H
#define MOVIE_H
#include <map>
#include <string>
#include <iostream>
using namespace std;
const string STRING_ARRAY [] = {"director","title","date","lead actor"};	//TODO: movie this somewhere else, (maybe factory?)
class Movie {
public:
	Movie();
	virtual ~Movie();
	virtual string genre() = 0;
	string movieDataString();
	virtual Movie* create() = 0;
	void addData(string,string);
private:
	map<string,string> movieData;
};

class ClassicMovie: public Movie {
public:
	virtual ClassicMovie* create(){return new ClassicMovie();}
	virtual string genre();
};

class DramaMovie: public Movie {
public:
	virtual DramaMovie* create(){return new DramaMovie();}
	virtual string genre();
};
class ComedyMovie: public Movie {
public:
	virtual ComedyMovie* create(){return new ComedyMovie();}
	virtual string genre();
};
#endif