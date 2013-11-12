#ifndef COLLECTIONTREE_H
#define COLLECTIONTREE_H
#include "nodedata.h"

class CollectionTree {  
	friend ostream & operator<<(ostream &, const CollectionTree &);

public:
	CollectionTree(); 						// BinTree constructor 
	CollectionTree(const CollectionTree &); 		// BinTree copy constructor	
	~CollectionTree(); 					// BinTree destructor, calls makeEmpty 
	bool isEmpty() const; // true if tree is empty, otherwise false 
	void makeEmpty(); // empties the tree, calls makeEmpty() helper 
	bool insert(NodeData*);					// Insert node
	bool retrieve(NodeData*) const; // retrieves a node identical to parameter
	void inorderDisplay() const;
 
private:
	struct ListNode
	{	
		BinTree* mediaTree;
		ListNode* next;
	};
	ListNode* root;
};

#endif
