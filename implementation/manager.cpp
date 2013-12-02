#include "manager.h"

//TODO: make manager display all through a command, rather than just calling the method.
//TODO: fully implement Errors (figure out which methods are supposed to call them
	//and what they should do)
//TODO: implement Events

Manager::Manager(){
    productDB = new ProductCollection();
    customerDB = new CustomerIndex();
    mFactory = new ProductFactory();	//should this take pCollect arg or no? 
    cFactory = new CommandFactory(customerDB, productDB); 
}

Manager::~Manager(){
	delete productDB;
	productDB = NULL;
	delete customerDB;
	customerDB = NULL;
	delete mFactory;
	mFactory = NULL;
	delete cFactory;
	cFactory = NULL;
}

bool Manager::inputProduct(ifstream& productInput){
	std::string genre;
	for(;;){
		if(productInput.eof()) break;
		productInput >> genre;
		Product* p = mFactory -> create(genre);
		if(p == NULL){	//case for invalid genre
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
		if(productDB -> insert(p,genre).getErrorMessage() != "") delete p;
	}
	return true;
}

bool Manager::inputCustomer(ifstream& customerInput){
	//TODO
	return false;
}

bool Manager::inputCmd(ifstream& cmdInput){	
	std::string command;
	for(;;){
		if(cmdInput.eof()) break;
		cmdInput >> command;
		Command* c = cFactory -> create(command);
		if(c == NULL){	//case for invalid command
			std::string temp;
			getline(cmdInput, temp);
			continue;
		}
		cmdInput.get();
		//TODO
		break;
	}
	return true;
}

//TEMPORARY. replace with event.
void Manager::displayAll() const{
	productDB -> displayAll();
}
//TEMPORARY