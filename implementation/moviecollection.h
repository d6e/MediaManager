/*
#ifndef MOVIECOLLECTION_H
#define MOVIECOLLECTION_H

#include "bintree.h"

class GenreNode{
	friend class MovieCollection;
	friend ostream & operator<<(ostream &, const GenreNode &);
public:
	GenreNode();
	string genre();
	bool isEmpty() const;
//constructor that takes bintree arg, maybe?
private:
	BinTree* movieData;
	GenreNode* next;
};

class MovieCollection{
	friend ostream & operator<<(ostream &, const MovieCollection &);
public:
	MovieCollection();
	void insert(Movie *);	//primary insert method
	bool isEmpty() const;
	void collectionToArray(BinTree* []) const;
private:
	void initializeArrayHelper(BinTree* []) const;
	GenreNode* root;
};
#endif
*/