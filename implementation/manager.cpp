#include "manager.h"

//TODO: implement customers
//TODO: implement all commands
//TODO: fully implement Errors (figure out which methods are supposed to call them
	//and what they should do)

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
	std::string custId;
	std::string lastName;
	std::string firstName;
	for(;;){
		if(customerInput.eof()) break;
		customerInput >> custId;
		customerInput.get();
		customerInput >> lastName;
		customerInput.get();
		customerInput >> firstName;
		customerInput.get();
		Customer* c = new Customer();
		c -> setData(custId,lastName,firstName);
		customerDB -> insertCustomer(c);	//TODO: implement this in customerindex
		cout << *c << endl;
		//TODO
	}
	return true;
}

bool Manager::inputCmd(ifstream& cmdInput){	
	std::string command;
	Event* e = new Event();
	for(;;){
		if(cmdInput.eof()) break;
		cmdInput >> command;
		Command* c = cFactory -> create(command,productDB,customerDB);
		if(c == NULL){	//case for invalid command
			std::string temp;
			getline(cmdInput, temp);
			continue;
		}
		if(command == "S"){
			c -> execute();
			delete c;
			continue;
		}
		cmdInput.get();
		e -> makeEmpty();
		e -> set(cmdInput);	//TODO: keep in mind this is of type error
		c -> setData(e);
		c -> execute();
		delete c;
		c = NULL;
	}
	delete e;
	e = NULL;
	return true;
}