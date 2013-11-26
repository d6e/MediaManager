#include "productcollection.h"

ProductCollection::ProductCollection(){
	//int collectionSize = sizeof(collectTree)/sizeof(*collectTree);
	//for(int i = 0; i < collectionSize; i++){

	//}
} //TODO

ProductCollection::~ProductCollection(){} //TODO

Error ProductCollection::insert(Product* p){
	Error empty;
	int index = 0;	//TODO: change to index based on the product's proper letter.
	if(collectTree[index].insert(p)) return empty;
	Error notFound("ERROR: failed to insert the product.");	//TODO: this might not actually be what "false" means in this context.
	return notFound;
}

Error ProductCollection::retrieve(Product* p){
	Error empty;
	//TODO
	return empty;
}

Error ProductCollection::displayAll() const{
	Error empty;
	int collectionSize = sizeof(collectTree)/sizeof(*collectTree);
	for(int i = 0; i < collectionSize; i++){
		if(!collectTree[i].isEmpty()) cout << collectTree[i];
	}
	return empty;
	
}