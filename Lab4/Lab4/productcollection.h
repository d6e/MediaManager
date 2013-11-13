#ifndef MEDIACOLLECTION_H
#define MEDIACOLLECTION_H
#include "error.h"
#include "media.h"
#include "collectiontree.h"
#include "mediacollection.h"
#include <string>



class MediaCollection{
	friend ostream & operator<<(ostream &, const MediaCollection &);
public:
	MediaCollection();
	~MediaCollection();
	//goes through ListNode linked list, comparing each Node's dataType() 
	//to the inserted Media's dataType() and inseting when it finds a match.
	//(this means media type and genre must match.) if no match is found, a new
	//ListNode is created and the Media is inserted into its tree.
	Error insert(Media *);
	Error retrieve(Media *);
	Error displayAll() const;
	bool isEmpty() const;
private:
	CollectionTree* collectTree;
};
#endif