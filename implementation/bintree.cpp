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
    makeEmpty();
}    

void BinTree::makeEmpty(){
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
void BinTree::makeEmpty(Node *currNodeNode){
    if(currNodeNode != NULL){
        makeEmpty(currNodeNode->left);
        makeEmpty(currNodeNode->right);
        delete currNodeNode;
        currNodeNode = NULL;
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
bool BinTree::insert(NodeData* insertNode){
    if(insertNode == NULL){ //can't insert null 
        return false;
    }
    if(root == NULL){ //if empty, insert at root
        root = new Node();
        root->data = insertNode;
        return true;   
    }
    if(*insertNode == *(root->data)){ //if nodes match
        root->data->incrProductQuantity(insertNode); //increment quantity
        return false;
    }
    if(*insertNode < *(root->data)){ // recurse left
        return insert(insertNode, root, root->left,false);
    }
    else{                            // recurse right
        return insert(insertNode, root, root->left, true);
    }
}

// --------------------------------------------------------------------------
// Insert helper method 
// ptr is a NodeData pointer to the NodeData object to be inserted 
// cNode is the currNodeent node, while nNode is the next node to be used
// Recursively inserts the node in an inorder traversal.
bool BinTree::insert(NodeData *ptr, Node *cNode, Node *nNode, bool right){
    if(nNode == NULL){
        if(right){   //insert to the right
            cNode->right = new Node();
            cNode->right->data = ptr;
            return true;
        }
        else{    //insert to the left
            cNode->left = new Node();
            cNode->left->data = ptr;
            return true;
        }
    }
    if(*ptr == *(nNode->data)){   
        nNode->data->incrProductQuantity(ptr);
        return false;
    }
    if(*ptr < *(nNode->data)){   // recurse left
        return insert(ptr, nNode, nNode->left,false);
    }
    else{                        // recurse right
        return insert(ptr, nNode, nNode->right, true);
    }
}

// --------------------------------------------------------------------------
// Prints a Tree to the standard out in alphabetical order
std::ostream& operator<<(std::ostream& out, const BinTree& tree) {
    if(!tree.isEmpty()){
        tree.displayHelper(out,tree.root);
    }
    return out;
}

void BinTree::displayHelper(std::ostream& out, Node* cNode) const{
    if(cNode == NULL) return;
    displayHelper(out,cNode->left);
    out << *(cNode->data);
    displayHelper(out,cNode->right);
}

std::string BinTree::getName() const{
    if(root != NULL){
        return root->data->getName();
    }
    return NULL;
}

std::vector<std::string> BinTree::getDataTypes() const{ 
    std::vector<std::string> ret;
    if(root != NULL){
        ret = root->data->getDataTypes();
    }
    return ret;
}

int BinTree::getDataTypeSize() const{ 
    if(root != NULL){
        return root->data->getDataTypeSize();
    }
    return 0;
}

bool BinTree::retrieve(const NodeData* data) const{
    if(root == NULL){ //tree is empty
        return false;
    }
    if(*(root->data) == *data){  // if the data matches
        return true;
    }
    return retrieve(root->left, data) || retrieve (root->left, data);
} 

// --------------------------------------------------------------------------
// A helper for the retrieve method. It recurses to find the object passed
// from the original retrieve.
bool BinTree::retrieve(Node* currNode, const NodeData* data) const{
    if(currNode == NULL) {
        return false;
    }
    if(*(currNode->data) == *data){  // if the data matches
        return true;
    }
    bool ret = retrieve(currNode->left, data) || retrieve (currNode->left, data);
    return ret;
}
