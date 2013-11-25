#include "manager.h"

Manager::Manager(){
	//productDB = new CollectionTree();
//TODO: Initializes all collections and factories
}

bool Manager::inputProduct(ifstream& productInput){
	std::string genre;
	productInput >> genre;
	Product* p = mFactory.create(genre); //TODO: check valid genre
	productInput.get();
	const std::string* dataTypeNames = p -> dataTypeNames();
	const int dataTypeCount = p -> dataTypeCount();
	for(int i = 0; i < dataTypeCount-1; i++){	//TODO: error checking		
		string currentData;
		getline(productInput, currentData, ',');
		//TODO: this should probably use setData(Event) but I'm not positive.
		if(!p -> addData(dataTypeNames[i],currentData)) return false;  
	}
	
	string lastData;
	getline(productInput, lastData);

	if(!p -> addData(dataTypeNames[dataTypeCount-1],lastData)) return false;

	//p -> display();	//TEMPORARY FOR TESTING
	//TODO: actually insert product into collection
	return true;
}

//TEMPORARY
void Manager::displayAll(){

}
//TEMPORARY