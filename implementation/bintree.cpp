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


/*
// --------------------------------------------------------------------------
// Equality Operator
// Compares the data members of two node objects for equality. Returns true
// if they are equal
bool Node::operator==(const Node& rhs) const{
      return data == rhs.data;
}
*/
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
    if(*ptr < *(nNode->data)){         // go down the left side
        return insert(ptr, nNode, nNode->left,false);  // recurse left
    }
    else{                               // go down the right side
        return insert(ptr, nNode, nNode->right, true); // recurse right
    }
}
/*
// --------------------------------------------------------------------------
// getDepth
// Recursively finds the depth of the tree by calling the helper method
// getDepth(). At the end it uses maximum() to determine the final depth.
int BinTree::getDepth(const NodeData& data) const{ 
    if(root == NULL){ //an empty tree returns 0 for any depth
        return 0;
    }
    if(*(root -> data) == data){  
        return 1;                      //depth at the root is 1
    }
    int leftDepth = 0;
    if(root -> left != NULL){
        leftDepth = getDepth(*(root -> left),data,2);   // search left
    }
    int rightDepth = 0;
    if(root -> right != NULL){
        rightDepth = getDepth(*(root -> right),data,2); // search right
    }
    return max(leftDepth, rightDepth);
}

// --------------------------------------------------------------------------
//helper for one-arg depth method
// cNode represents the current node,"d" represents depth
// Recursively traverses down the tree, when reaching a null node it returns
// the depth. Then uses maximum() to determine the final depth.
int BinTree::getDepth(const Node& cNode,const NodeData& data, int d) const{
    if(*cNode.data == data){  
        return d;  //depth at the root is 1
    }
    int leftDepth = 0;
    if(cNode.left != NULL){
        leftDepth = getDepth(*cNode.left,data,d+1);
    }
    int rightDepth = 0;
    if(cNode.right != NULL){
        rightDepth = getDepth(*cNode.right,data,d+1);
    }
    return max(leftDepth,rightDepth);
}

// --------------------------------------------------------------------------
//a helper max function which returns the largest of two integers
int BinTree::maximum(const int num1, const int num2){   
    if(num1 > num2){
        return num1;
    }
    else{
        return num2;
    }
}
*/
// --------------------------------------------------------------------------
// Prints a Tree to the standard output in alphabetical order
std::ostream& operator<<(std::ostream& output, const BinTree& tree) {
    if(!tree.isEmpty()){
        tree.displayHelper(output,tree.root);
    }
    return output;
}

void BinTree::displayHelper(std::ostream& output, Node* cNode) const{
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

const int BinTree::getDataTypeSize() const{ //TODO: getDataTypeSize() is new, rewrite everything else in this method
    if(root != NULL){
        return root -> data -> getDataTypeSize();
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
    /*
    if(root -> left != NULL){
        bool status = retrieve(root -> left, data,);   // go left
        if(status){        //if it returned true, return true
            return true;
        }
    }
    if(root->right != NULL){
        bool status = retrieve(root -> right, data, ret);   // go right
        if(status){        //if it returned true, return true
            return true;
        }
    }
    return false;    // node wasn't found
    */
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
    /*
    if(*(curr->data) == data){      // if we found the datas we're looking for
        ret = curr->data; // assign the address of the nodedata object to ret
        return true;
    }
    if(curr->left != NULL){
        bool status = retrieve(curr -> left, data, ret);   // go left
        if(status){                        //if it returned true, return true
            return true;
        }
    }
    if(curr->right != NULL){
        bool status = retrieve(curr -> right, data, ret);   // go right
        if(status){                        //if it returned true, return true
            return true;
        }
    }
    return false;    // node wasn't found

}
*/