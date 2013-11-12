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
	Node* root;						// root node of the binary tree 
	void copyNode(Node&, Node &);  // copy constructor helper method
	int getDepth(const Node &, const NodeData &, int) const; //getDepth helper 
	int maximum(const int, const int); //determines the higher of two integers
	void makeEmpty(Node*); 				 // helper for makeEmpty() 
	bool insert(NodeData*,Node*,Node*,bool); // helper for displaySideways() 
	void convertArrayToTree(NodeData*[], int); // arrayToBSTree helper
    void initializeArrayHelper(NodeData* []); // Sets array elements to NULL
	void inorderHelper(Node*,NodeData* [],int&) const;//does inorder traversal
	void cleanTree(Node *); // empties tree like empty tree but deletes datsa
	bool retrieve(Node*, const NodeData&, NodeData*&) const; //retrieve helper
	struct ListNode
	{	
		BinTree* mediaTree;
		ListNode* next;
	};
	ListNode* root;
};

#endif
