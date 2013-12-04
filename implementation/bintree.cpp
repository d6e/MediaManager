#include "bintree.h"

// --------------------------------------------------------------------------
// Node destructor
// Deletes a DataNode object and sets all the other members to NULL

BinTree::Node::~Node(){
    left = NULL;
    right = NULL;
    delete data;
    data = NULL;
}

// --------------------------------------------------------------------------
// BinTree Constructor
// Creates a tree object and sets its root data member to NULL

BinTree::BinTree(){
    root = NULL;
}

BinTree::~BinTree(){
	if(root != NULL){
        makeEmpty(root->left);
        makeEmpty(root->right);
        delete root;
        root = NULL;    
    }
}	

// --------------------------------------------------------------------------
// helper for makeEmpty
// Empties tree recursively, deleting each node.
void BinTree::makeEmpty(Node *currNode){
    if(currNode != NULL){
        makeEmpty(currNode->left);
        makeEmpty(currNode->right);
        delete currNode;
        currNode = NULL;
    }
}

// --------------------------------------------------------------------------
// isEmpty
// Checks whether the tree is emtpy and returns true if it is.
bool BinTree::isEmpty() const{  
    return root == NULL;
}

// --------------------------------------------------------------------------
// Insert method
// Recursively inserts the node in an inorder traversal by calling the 
// insert helper method.
bool BinTree::insert(NodeData* inserted){
	//cout << inserted -> dataString() << endl;
	if(inserted == NULL){ //cannot insert null data
		return false;
	}
	if(root == NULL){ //if the bintree is empty, insert the node at the root
		root = new Node();
		root -> data = inserted;
		return true;   
	}
	if(*inserted == *(root -> data)){ //check if node is already in the tree
		//case for matching data: increment count of standard format.
		root -> data -> duplicate(inserted);
		return false;
	}
	if(*inserted < *(root->data)){            // go down the left side
		return insert(inserted, root, root -> left,false);
	}
	else{                                     // go down the right side
		return insert(inserted, root, root -> left, true);
	}
}

// --------------------------------------------------------------------------
// Insert helper method 
// ptr is a NodeData pointer to the NodeData object to be inserted 
// cNode is the current node, while nNode is the next node to be used
// Recursively inserts the node in an inorder traversal.
bool BinTree::insert(NodeData *ptr, Node *cNode, Node *nNode, bool right){
	if(nNode == NULL){
		if(right){                          //the actual insertion (right)
			cNode->right = new Node();
			cNode->right->data = ptr;
			return true;
		}
		else{                               //the actual insertion (left)
			cNode->left = new Node();
			cNode->left->data = ptr;
			return true;
		}
	}
	if(*ptr == *(nNode->data)){   
		nNode -> data -> duplicate(ptr);
		return false;
	}
	if(*ptr < *(nNode->data)){ 		// go down the left side
		return insert(ptr, nNode, nNode->left,false);  // recurse left
	}
	else{                   			// go down the right side
		return insert(ptr, nNode, nNode->right, true); // recurse right
	}
}
// --------------------------------------------------------------------------
// Prints a Tree to the standard output in alphabetical order
ostream& operator<<(ostream& output, const BinTree& tree) {
	if(!tree.isEmpty()){
		tree.displayHelper(output,tree.root);
	}
	return output;
}

void BinTree::displayHelper(ostream& output, Node* cNode) const{
	if(cNode == NULL) return;
	displayHelper(output,cNode -> left);
	output << *(cNode -> data);
	displayHelper(output,cNode -> right);
}

const std::string BinTree::getKey() const{
	if(root != NULL){
		return root -> data -> getKey();
	}
	return NULL;
}

const std::string* BinTree::dataTypeNames() const{
	if(root != NULL){
		return root -> data -> dataTypeNames();
	}
	return NULL;
}

const int BinTree::dataTypeCount() const{
	if(root != NULL){
		return root -> data -> dataTypeCount();
	}
	return 0;
}

bool BinTree::retrieve(const NodeData* data) const{
    if(root == NULL){
        return false;  // node wasn't found
    }
    if(*(root->data) == *data){  // if we found the datas we're looking for
        return true;
    }
    return retrieve(root -> left, data) || retrieve (root -> left, data);
} 

// --------------------------------------------------------------------------
// A helper for the retrieve method. It recurses to find the object passed
// from the original retrieve.
bool BinTree::retrieve(Node* curr, const NodeData* data) const{
	if(curr == NULL) {
		return false;
	}
	if(*(curr->data) == *data){  // if we found the datas we're looking for
        return true;
    }
    return retrieve(curr -> left, data) || retrieve (curr -> left, data);
}

NodeData* BinTree::pullData(NodeData* n, std::string transactionType){
	if(root == NULL){
        return NULL;  // node wasn't found
    }
    bool returning = false;
	if(transactionType == "R"){
		returning = true;
	}
	else if(transactionType != "B"){
		return NULL;
	}
    if(*(root -> data) == *n){  // if we found the datas we're looking for
    	NodeData* found = root -> data;
    	if(returning == false && !found -> available()){
    		return NULL;
    	}
    	found -> adjustCount(returning);
        return found;
    }
    NodeData* left = pullData(root -> left, n, returning);
    if(left != NULL){
    	return left;
    }
    return pullData(root -> right, n, returning);
}

NodeData* BinTree::pullData(Node* curr, const NodeData* data, bool returning){
	if(curr == NULL){
        return NULL;  // node wasn't found
    }
    if(*(curr -> data) == *data){  // if we found the datas we're looking for
    	NodeData* found = curr -> data;
    	if(returning == false && !found -> available()){
    		return NULL;
    	}
    	found -> adjustCount(returning);
        return found;
    }
    NodeData* left = pullData(curr -> left, data, returning);
    if(left != NULL){
    	return left;
    }
    return pullData(curr -> right, data,returning);
}