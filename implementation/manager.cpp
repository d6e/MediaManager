#include "manager.h"

//TODO: implement movie formats
//TODO: deal with sorting matches
//TODO: fully implement Errors (figure out which methods are supposed to call them
	//and what they should do)
//TODO: implement Events

Manager::Manager(){
	//productDB = new CollectionTree();
//TODO: Initializes all collections and factories
}

bool Manager::inputProduct(ifstream& productInput){
	std::string genre;
	for(;;){
		if(productInput.eof()) break;
		productInput >> genre;
		Product* p = mFactory.create(genre);
		if(p == NULL){
			std::string temp;
			getline(productInput, temp);
			continue;
		}
		
		productInput.get();
		const std::string* dataTypeNames = p -> dataTypeNames();
		const int dataTypeCount = p -> dataTypeCount();
		for(int i = 0; i < dataTypeCount-1; i++){	//TODO: error checking		
			string currentData;
			getline(productInput, currentData, ',');

			productInput.get();
		//TODO: this should probably use setData(Event) but I'm not positive.
			if(!p -> addData(dataTypeNames[i],currentData)){ 
				return false;
			}  
		}
	
		string lastData;
		getline(productInput, lastData);

		if(!p -> addData(dataTypeNames[dataTypeCount-1],lastData)) return false;
		//cout << "INSERTING" << endl;
		productDB.insert(p,genre);

	}
	return true;
}

//TEMPORARY. replace with event.
void Manager::displayAll() const{
	productDB.displayAll();
}
//TEMPORARY