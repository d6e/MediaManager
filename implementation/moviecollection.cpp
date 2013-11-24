/*
#include "moviecollection.h"

//GenreNode
GenreNode::GenreNode(){
	movieData = new BinTree();
	next = NULL;
}

string GenreNode::genre(){
	if(movieData == NULL) return "";
	return movieData -> genre();
}

bool GenreNode::isEmpty() const{
	return movieData -> isEmpty();
}

//MovieCollection
MovieCollection::MovieCollection(){
	root = NULL;
}

void MovieCollection::insert(Movie *inserted){	//consider making this a bool rather than void, if useful
	if(inserted == NULL) return;
	if(root == NULL){
		root = new GenreNode();
		(root -> movieData) -> insert(new NodeData(inserted));
		return;
	}
	GenreNode* current = root;
	string insertedGenre = inserted -> genre();
	while(current -> next != NULL && current -> genre() != insertedGenre){
		current = current -> next;
	}
	if(current -> genre() != insertedGenre){
		current -> next = new GenreNode();
		current = current -> next;
	}
	(current -> movieData) -> insert(new NodeData(inserted));
}

bool MovieCollection::isEmpty() const{
	return root == NULL;
}

//for printing the whole collection
ostream& operator<<(ostream& output, const MovieCollection& movies) {
	BinTree* array[100];  //assuming there won't be more than 100 nodes TODO make more general
	movies.collectionToArray(array);
	if(array[0] != NULL){
		output << array[0] -> genre() << " movies: " << endl << endl;
		output << *array[0] << endl;
	}
	for(int i = 1; i < 100 && array[i] != NULL; i++){
		output << array[i] -> genre() << " movies:" << endl << endl;
		output << *array[i] << endl;
	}
	return output;
}

void MovieCollection::collectionToArray(BinTree* array[]) const{
	if(isEmpty()) return;
	initializeArrayHelper(array);
	GenreNode* current = root;
	int index = 0;
	while(current != NULL){
		array[index] = current -> movieData;
		current = current -> next;
		index++;
	}
}

void MovieCollection::initializeArrayHelper(BinTree* array[]) const{
	for(int i = 0; i < 100; i++){
		array[i] = NULL;
	}
}
*/