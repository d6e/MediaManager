#ifndef MEDIACOLLECTION_H
#define MEDIACOLLECTION_H

#include "collectiontree.h"

class ListNode{
	friend class MediaCollection;
	friend ostream & operator<<(ostream &, const MediaCollection &);
public:
	ListNode();
	~ListNode();
	string dataType() const;	//gives the node's dataType using the tree's dataType
	bool isEmpty() const;
private:
	CollectionTree* mediaData;
	ListNode* next;
};

class MediaCollection{
	friend ostream & operator<<(ostream &, const MediaCollection &);
public:
	MediaCollection();
	~MediaCollection();
	//goes through ListNode linked list, comparing each Node's dataType() 
	//to the inserted Media's dataType() and inseting when it finds a match.
	//(this means media type and genre must match.) if no match is found, a new
	//ListNode is created and the Media is inserted into its tree.
	void insert(Media *);	
	bool isEmpty() const;
	void collectionToArray(CollectionTree* []) const;
private:
	void initializeArrayHelper(CollectionTree* []) const;
	ListNode* root;
};
#endif