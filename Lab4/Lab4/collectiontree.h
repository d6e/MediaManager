#ifndef COLLECTIONTREE_H
#define COLLECTIONTREE_H
#include "nodedata.h"

class Node{
    friend class CollectionTree;

public:
	Node();  			   			   	  // Node constructor
	Node(const Node &);  				  // copy constructor
	~Node();  			  				  // Node destructor
	bool operator==(const Node &) const;  // Node equality operator
 
private:
	NodeData* data; 			          // pointer to data object 
	Node* left; 				          // left subtree pointer 
	Node* right; 				          // right subtree pointer 
};

class CollectionTree {  
	friend ostream & operator<<(ostream &, const CollectionTree &);

public:
	//TODO: consider removing methods we aren't using
	CollectionTree(); 						// BinTree constructor 
	CollectionTree(const CollectionTree &); 		// BinTree copy constructor	
	~CollectionTree(); 					// BinTree destructor, calls makeEmpty 
	bool isEmpty() const; // true if tree is empty, otherwise false 
	void makeEmpty(); // empties the tree, calls makeEmpty() helper 
	CollectionTree& operator=(const CollectionTree &);    // BinTree Assignment operator
	bool insert(NodeData*);					// Insert node method
	void bstreeToArray(NodeData* []); //converts bstree to an arary
	void arrayToBSTree(NodeData* []); //converts array to bstree
	int getDepth(const NodeData &) const; // gets the depth of the tree
	bool retrieve(string[]) const; // retrieves a node
	string dataType() const;	   //returns type of data stored in the tree. Calls dataType() for the root node.
 
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
};

#endif
