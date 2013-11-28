#ifndef BINTREE_H
#define BINTREE_H
#include <iostream>
#include <string>
#include "nodedata.h"

/*BinTree is a standard binary tree that will sort inputted data objects as 
nodes. The first inputted data becomes is the root, and the rest are sorted by 
applying their comparison operators to existing nodes, sorting smaller-valued
data "left", higher-valued data "right", and not inserting data that is equal to
existing data.
 
The NodeData stored in each Node is of a general type, meaning the bintree
can store any kind of data that can inherit from the nodedata class, and 
meaningfully sort this data as long as its instances have meaningful comparison
operators, and as long all data in the bintree is of the same type. (For 
example, a bintree of ComedyMovies is sorted first by title, then by date.)

The << operator displays each item in the tree in sorted order. In order for it
to work, the type of NodeData in the tree mus have a << operator as well. It
calls displayInOrder() to help sort the tree's data in the proper order.

BinTree's destructor calls makeEmpty(), which recursively deletes nodes and
their nodeData from the bottom up.

isEmpty() only needs to check the root of the tree to determine whether it is 
empty, since a NULL root should always mean an empty tree.

BinTree's = operator calls makeEmpty(), and then populates the tree with the
same data as the right hand side of the expression. The latter process should
work the same in the copy constructor.

The insert() function attempts to insert a new node created from the NodeData
arg, and returns true if the node was successfully inserted (i.e., if there are
no duplicates according to the == operator). 

When the tree is used to store 
Products, each inserted Product is sorted based on its sorting order (ex: date,
then famous actor), and if a duplicate is found, the Product stored in the 
existing Node has its quantity incremented by some number (currently 10) which
represents the quantity of each Product entered into the system.

retrieve() searches the tree for a NodeData using its comparison operators, 
returning false if it is not found and true if it is. It should return false
immediately if the data searched is not of the same type contained in the tree
(for instance, searching for a book in a tree of comedy movies).
*/

class BinTree {

// ostream is for all output
friend std::ostream& operator<<(std::ostream&, const BinTree&);

public:

    BinTree();              // No argument constructor
    BinTree(const BinTree & );   // copy constructor

    virtual ~BinTree();            //destructor

    bool isEmpty() const;  //checks if the tree is empty
    void makeEmpty();      //makes the tree empty
    BinTree& operator=(const BinTree &);  //sets the tree equal to another tree

    bool insert( NodeData*); // insert new object
    bool retrieve( NodeData*) const; //searches the Tree for a NodeData object

    int getSize() const;        //returns the number of nodes in the tree

    const std::string getKey() const;
   	const std::string* dataTypeNames() const;
   	const int dataTypeCount() const;
private:
    struct Node {
        NodeData* data;
        Node* left;
        Node* right;
    };
    Node* root;
    // string displaying the tree (helper for <<)
    std::string displayInOrder() const;
    bool insert(NodeData*,Node*,Node*,bool); //helper for insert(NodeData*)
    void displayHelper(ostream&,Node*) const;
//friend std::ostream& operator<<(std::ostream& output, const Node&);
};
/*
#ifndef BINTREE_H
#define BINTREE_H
#include "nodedata.h"

class Node{
    friend class BinTree;

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

class BinTree {  
	friend ostream & operator<<(ostream &, const BinTree &);

public:
	//TODO: consider removing methods we aren't using
	BinTree(); 						// BinTree constructor 
	BinTree(const BinTree &); 		// BinTree copy constructor	
	~BinTree(); 					// BinTree destructor, calls makeEmpty 
	bool isEmpty() const; // true if tree is empty, otherwise false 
	void makeEmpty(); // empties the tree, calls makeEmpty() helper 
	BinTree& operator=(const BinTree &);    // BinTree Assignment operator
	bool operator==(const BinTree &) const; // BinTree Equality operator
	bool operator!=(const BinTree &) const; // BinTree Inequality operator
	bool insert(NodeData*);					// Insert node method
	void bstreeToArray(NodeData* []); //converts bstree to an arary
	void arrayToBSTree(NodeData* []); //converts array to bstree
	int getDepth(const NodeData &) const; // gets the depth of the tree
	bool retrieve(const NodeData &, NodeData*&) const; // retrieves a node
	void displaySideways() const; // provided, displays the tree sideways
	string genre();
 
private:
	Node* root;						// root node of the binary tree 
	void copyNode(Node&, Node &);  // copy constructor helper method
	int getDepth(const Node &, const NodeData &, int) const; //getDepth helper 
	int maximum(const int, const int); //determines the higher of two integers
	bool isEqual(const Node&,const Node&)const;      // helper for operator==
	bool isNotEqual(const Node&,const Node&)const;   // helper for operator==
	void makeEmpty(Node*); 				 // helper for makeEmpty() 
	bool insert(NodeData*,Node*,Node*,bool); // helper for displaySideways() 
	void convertArrayToTree(NodeData*[], int); // arrayToBSTree helper
    void initializeArrayHelper(NodeData* []); // Sets array elements to NULL
	void inorderHelper(Node*,NodeData* [],int&) const;//does inorder traversal
	void cleanTree(Node *); // empties tree like empty tree but deletes data
	void sideways(Node*, int) const; // helper for displaySideways() 
	bool retrieve(Node*, const NodeData&, NodeData*&) const; //retrieve helper
};
*/
#endif
