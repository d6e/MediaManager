/*
#ifndef MOVIELIST_H
#define MOVIELIST_H
#include "movie.h"
//a movie list is a set of movies which are sorted the same way, but differ in details.
class MovieNode{
	friend class MovieList;
public:
	MovieNode();
private:
	Movie* data;
	MovieNode* next;
};

class MovieList{
public:
	MovieList();
	void insert(Movie *);
private:
	MovieNode* root;
};
#endif
*/