#ifndef MEDIACOLLECTION_H
#define MEDIACOLLECTION_H

#include "collectiontree.h"

class ListNode{
	friend class MediaCollection;
	friend ostream & operator<<(ostream &, const MediaCollection &);
public:
	ListNode();
	~ListNode();
	string genre();
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
	void insert(Media *);
	bool isEmpty() const;
	void collectionToArray(CollectionTree* []) const;
private:
	void initializeArrayHelper(CollectionTree* []) const;
	ListNode* root;
};
#endif