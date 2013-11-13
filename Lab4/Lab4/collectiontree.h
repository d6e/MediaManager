#ifndef COLLECTIONTREE_H
#define COLLECTIONTREE_H
#include "nodedata.h"
#include "bintree.h"

/*
A CollectionTree is a linked list of binary trees. 

Each ListNode has a key and a BinaryTree. When inserting a NodeData, 
the NodeData will be inserted into the binary tree whose ListNodes key
matches with NodeData.getKey(). If no LIstNode has a matching key, 
then a new ListNode is created with NodeData.getKey() and NodeData
is inserted into that binary tree.
*/
class CollectionTree {  
public:
	CollectionTree(); 						//  constructor 
	CollectionTree(const CollectionTree &); 		
	~CollectionTree(); 					//  destructor, calls makeEmpty 
	bool isEmpty() const; // true if collection tree is empty, otherwise false 
	void makeEmpty(); // empties the collection tree, calls makeEmpty() helper 
	bool insert(NodeData*);					// Insert node
	bool retrieve(NodeData*) const; // retrieves a node identical to parameter
	void inorderDisplay() const;
 
private:
	struct ListNode
	{	
		std::string key;
		BinTree* productTree;
		ListNode* next;
	};
	ListNode* root;
};

#endif
