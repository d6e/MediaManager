#ifndef COLLECTIONTREE_H
#define COLLECTIONTREE_H
#include "nodedata.h"
#include "bintree.h"

/*
A CollectionTree is a linked list of binary trees. 

Each ListNode has a key and a BinaryTree. When inserting a NodeData, 
the NodeData will be inserted into the binary tree whose ListNodes key
matches with NodeData.getKey(). If no ListNode has a matching key, 
then a new ListNode is created with NodeData.getKey() and NodeData
is inserted into that binary tree.

The CollectionTree stores a ListNode as its root. From the root, the rest of
the nodes in the list can be accessed by following each node's "next" ListNode.

The CollectionTree's default constructor sets the root to NULL.

The copy constructor must make a copy of each node in the other CollectionTree,
starting with the root. Each node calls the BinTree's copy constructor to set
productTree.

The destructor calls makeEmpty(), which uses a while loop to delete each Node 
(including each Node's tree), starting from the root and iterating through until 
the next node pointer is NULL. However, makeEmpty() is a public method, not a 
private helper method, because it may be useful to empty a collection tree
before filling it with new data, rather than entirely deleting it.

insert() inserts a NodeData (the object type stored in a BinTree's nodes) into 
the collectiontree, returning true if it was successfully inserted and false if
it was not. In order to find the correct BinTree node, each ListNode (starting 
with root) is checked against the inserted NodeData's getKey(). If a match is
found, the data is insertend into the matching ListNode's BinTree using the 
BinTree insert() method. If insert() reaches the end of the node list without 
finding a match, it adds a new node onto the end, creating a new BinTree in the 
process (with the inserted NodeData as its root data).

(Note that insert() still returns true if a new BinTree is created, and does not
check for invalid NodeData since this should happen earlier in the program's 
execution. insert() *only* returns false if it finds duplicate data via 
BinTree's insert().)

retrieve() searches for a NodeData through essentially the same process as
insert(), traversing the nodes and checking for a match with getKey(), and then
calling the matching node's bintree's retrieve(). Unlike insert(), retrieve()
returns false if it reaches the last ListNode without finding a match.
*/

class CollectionTree {  
public:
	CollectionTree(); 						//  constructor 
	CollectionTree(const CollectionTree &); //copy constructor	
	virtual ~CollectionTree(); 					//  destructor, calls makeEmpty 
	bool isEmpty() const; // true if collection tree is empty, otherwise false 
	void makeEmpty(); // empties the collection tree
	bool insert(NodeData*);					// Insert node
	bool retrieve(NodeData*) const; // retrieves a node identical to parameter
	void inorderDisplay() const;	//displays the tree in order
 
private:
	struct ListNode
	{	
		std::string key;	
		BinTree* productTree;
		ListNode* next;
	};
	ListNode* root;
	//gets a unique key identifying a ListNode's associated object
	std::string getKey(const ListNode) const;
};

#endif
