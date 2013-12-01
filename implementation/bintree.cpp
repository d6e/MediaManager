#include "bintree.h"

//-------------------------------------------------------------------------
// Node constructor
// Creates a node object and sets it to NULL
/*
BinTree::Node::Node(){
    left = NULL;
    right = NULL;
    data = NULL;
}

// --------------------------------------------------------------------------
// Node copy constructor
// Copies a node that is passed by reference 
BinTree::Node::Node(const Node& otherNode){
  	data = new NodeData(*otherNode.data);
 	left = NULL;
  	right = NULL;
}

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
	//makeEmpty();
}	//TODO



/*
// --------------------------------------------------------------------------
// BinTree copy constuctor 
// Copies a tree that is passed by reference 
BinTree::BinTree(const BinTree& otherTree){ 
 	if(otherTree.isEmpty()){
    	return;
 	}

  	root = new Node(*otherTree.root);

 	if(otherTree.root -> left != NULL){
   		root -> left = new Node();
    	copyNode(*(root -> left), *(otherTree.root -> left));
  	}
  	if(otherTree.root -> right != NULL){
    	root -> right = new Node();
   		copyNode(*(root -> right), *(otherTree.root -> right));
  	}
}

// --------------------------------------------------------------------------
// BinTree Copy Constructor Helper
// Helps copy constructor perform a deep copy on the tree
void BinTree::copyNode(Node& currNode, Node& otherNode){  
  	currNode.data = new NodeData(*otherNode.data);
 
  	if(otherNode.left != NULL){
    	currNode.left = new Node();
    	copyNode(*currNode.left, *otherNode.left);
  	}
  	if(otherNode.right != NULL){
    	currNode.right = new Node();
    	copyNode(*currNode.right, *otherNode.right);
  	}
}

// --------------------------------------------------------------------------
// BinTree Destructor
// Calls makeEmpty to destroy the tree.
BinTree::~BinTree(){
    makeEmpty();
}
*/
// --------------------------------------------------------------------------
// isEmpty
// Checks whether the tree is emtpy and returns true if it is.
bool BinTree::isEmpty() const{  
    return root == NULL;
}
/*
// --------------------------------------------------------------------------
// makeEmpty
// Empties the tree recursively by calling the helper makeEmpty(). Deletes the root ndoe. 
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
void BinTree::makeEmpty(Node *currNode){
    if(currNode != NULL){     
        makeEmpty(currNode->left);
        makeEmpty(currNode->right);
        delete currNode;
        currNode = NULL;
    }
}

// --------------------------------------------------------------------------
// Assignment Operator
BinTree& BinTree::operator=(const BinTree &otherTree){
  	if (this != &otherTree) {
		makeEmpty();
		root = new Node(*otherTree.root);

		if(otherTree.root -> left != NULL){
			root -> left = new Node();
			copyNode(*(root -> left), *(otherTree.root -> left));

		}
		if(otherTree.root -> right != NULL){
		root -> right = new Node();
		copyNode(*(root -> right), *(otherTree.root -> right));
	  	}
    }
    return *this;
}

// --------------------------------------------------------------------------
// Equality Operator
bool BinTree::operator==(const BinTree& otherTree)const{
	return isEqual(*root,*otherTree.root);
}

// --------------------------------------------------------------------------
// Determines whether two nodes are equal, returns true if they are
bool BinTree::isEqual(const Node &node1, const Node &node2)const{
	if(*node1.data != *node2.data){
		return false;
	}
	if(node1.left == NULL && node1.right == NULL
			&& node2.left == NULL && node2.right == NULL){
		return true;
	}
	if((node1.left == NULL) != (node2.left == NULL)
			|| (node1.right == NULL) != (node2.right == NULL)){
		return false;
	}
	if(node1.left == NULL && node1.left == NULL){
		return isEqual(*node1.right,*node2.right);
	}
	if(node1.right == NULL && node1.right == NULL){
		return isEqual(*node1.left,*node2.left);
	}

  	return(
		isEqual(*node1.left,*node2.left) &&
		isEqual(*node1.right,*node2.right)
  	);
}

// --------------------------------------------------------------------------
// Inequality operator
// Checks whether two node objects are equal or not
bool BinTree::operator!=(const BinTree& otherTree)const{
 	return isNotEqual(*root,*otherTree.root);
}

// --------------------------------------------------------------------------
// Inequality operator helper
// Checks whether two node objects are equal or not, returns true if they are
bool BinTree::isNotEqual(const Node &node1, const Node &node2)const{
	if(*node1.data != *node2.data){
		return true;
	}
	if(node1.left == NULL && node1.right == NULL
			&& node2.left == NULL && node2.right == NULL){
		return false;
	}
	if((node1.left == NULL) != (node2.left == NULL)
			|| (node1.right == NULL) != (node2.right == NULL)){
		return true;
	}
	if(node1.left == NULL && node1.left == NULL){
		return isNotEqual(*node1.right,*node2.right);
	}
	if(node1.right == NULL && node1.right == NULL){
		return isNotEqual(*node1.left,*node2.left);
	}

	return(
		isNotEqual(*node1.left,*node2.left) ||
		isNotEqual(*node1.right,*node2.right)
	);
}
*/

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
		return 1;  					//depth at the root is 1
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
/*

// --------------------------------------------------------------------------
// bstreeToArray
// Fills an array of NodeData* via an inorder traversal of the tree. 
// It empties the tree at the end.
void BinTree::bstreeToArray(NodeData* array[]){
  	initializeArrayHelper(array);			//sets the array to NULL
  	int startValue = 0;						//for calling the inorderHelper
  	inorderHelper(root,array,startValue);	//do an inorder traversal
    if(root != NULL){						//delete the old tree	
        cleanTree(root->left);
        cleanTree(root->right);
        root->data = NULL;
        delete root;
        root = NULL;    
    }
}

// --------------------------------------------------------------------------
// InitializeArrayHelper
// Sets array elements to NULL
void BinTree::initializeArrayHelper(NodeData* array[]){
	for(int i = 0; i < 100; i++){
		array[i] = NULL;
	}
}

// --------------------------------------------------------------------------
// inorderHelper
// Performs an inorder traversal of the tree copying the NodeData objects
// to an array.
// cNode represents the current node
void BinTree::inorderHelper(Node* cNode, NodeData* arr[], int& index) const {
	if(cNode -> left != NULL){     // if there's a node to the left
		inorderHelper(cNode -> left, arr, index);  // recurse left
	}
	arr[index] = (cNode -> data);	// load NodeData pointer into array
	index++;							   
	if(cNode->right != NULL){		// if there's a node to the right
		inorderHelper(cNode -> right, arr, index);  // recurse right
	}
}

// --------------------------------------------------------------------------
// cleanTree
// Like emptyTree, but sets all the nodes and their data to NULL.
// Also deletes the existing nodes in the tree. Necessary for efficiency.
void BinTree::cleanTree(Node *currNode){
    if(currNode != NULL){     
        cleanTree(currNode->left);
        cleanTree(currNode->right);
		currNode->data = NULL;
        delete currNode;
        currNode = NULL;
    }
}
*/
/*
//--------------------------------------------------------------------------
// arrayToBSTree
// Builds a balanced BinTree from a sorted array of NodeData* leaving the 
// array filled with NULLs. The root (recursively) is at (low+high)/2 where 
// low is the lowest subscript of the array range and high isthe highest. 
void BinTree::arrayToBSTree(NodeData* array[]){
	// have to determine exact array size
	int arrSize = 0;
	for(int i = 0; i <= 100; i++){  // Have to assume the size is 100
		if(array[i] == NULL){    	// Break if you reach NULL 
			break;
		};
		arrSize++;
	}  
	convertArrayToTree(array, arrSize); //does the actual the conversion
	for(int i = 0; i < arrSize; i++){  // Fill the array with NULLS
		array[i] = NULL;
	}
}

// --------------------------------------------------------------------------
// arrayToBSTree helper
// Inserts the middle element in each array, the rest gets copied into two
// subarrays, left and right, based on their position relative to the
// middle element.
void BinTree::convertArrayToTree(NodeData* array[], int size){
	int low = 0;
	int high = size-1;   
	int mid = (low+high)/2;     	// This is the node we insert
	int lsize = mid;				// size of left subarray 
	int rsize = high-mid;			// size of right subarray 

	insert(array[mid]);  			// insert the node
	if(lsize == 0 && rsize == 0){   // break out of the recursion
		return;
	}

	if(lsize > 0){   				// do the left
		NodeData** leftArr = new NodeData*[lsize]; //make subarrays
		for(int i = 0; i < mid; i++){   // copy array into subarrays
			leftArr[i] = array[i];
		}
		convertArrayToTree(leftArr, lsize);    //recurse left	
		delete [] leftArr;					   //delete the unused subarray
	}
		
	if(rsize > 0){     								  // do the right
		NodeData** rightArr = new NodeData*[rsize];   //make subarrays
		int count = 0;
		for(int i = mid+1; i <= high; i++){   // copy array into subarrays
			rightArr[count] = array[i];
			count++; //counter to start right array at zero
		}	
		convertArrayToTree(rightArr, rsize); //recurse right
		delete [] rightArr;					 //delete the unused subarray
	}
}

// --------------------------------------------------------------------------
// Retrieves a NodeData* of a Node in the tree. It returns true if found. 
// Once found the second parameter is set to the found NodeData object. 
bool BinTree::retrieve(const NodeData& data, NodeData*& ret) const{
    if(root == NULL){
        return false;  // node wasn't found
    }
    if(*(root->data) == data){  // if we found the datas we're looking for
        ret = root -> data; // return the address of the nodedata object 
        return true;
    }
    if(root -> left != NULL){
        bool status = retrieve(root -> left, data, ret);   // go left
        if(status){		//if it returned true, return true
        	return true;
        }
    }
    if(root->right != NULL){
        bool status = retrieve(root -> right, data, ret);   // go right
	    if(status){		//if it returned true, return true
        	return true;
        }
    }
    return false;    // node wasn't found
} 

// --------------------------------------------------------------------------
// A helper for the retrieve method. It recurses to find the object passed
// from the original retrieve.
bool BinTree::retrieve(Node* curr, const NodeData& data, NodeData*& ret) const{
    if(*(curr->data) == data){      // if we found the datas we're looking for
        ret = curr->data; // assign the address of the nodedata object to ret
        return true;
    }
    if(curr->left != NULL){
        bool status = retrieve(curr -> left, data, ret);   // go left
        if(status){						//if it returned true, return true
        	return true;
        }
    }
    if(curr->right != NULL){
        bool status = retrieve(curr -> right, data, ret);   // go right
        if(status){						//if it returned true, return true
        	return true;
        }
    }
    return false;    // node wasn't found
}

//---------------------------------------------------------------------------
// displaySideways 
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
void BinTree::displaySideways() const {
    sideways(root, 0);
}

// --------------------------------------------------------------------------
// Helper method for printing the tree sideways
void BinTree::sideways(Node* current, int level) const {
	if (current != NULL) {
		level++;
		sideways(current -> right, level);
		// indent for readability, 4 spaces per depth level 
		for(int i = level; i >= 0; i--) {
		    cout << "    ";
		}
	    cout << *current -> data << endl;        // display information of object
	    sideways(current -> left, level);
	}
}

string BinTree::genre(){
	if(root == NULL) return "";
	return (*root -> data).genre();
}
*/