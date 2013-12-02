#include "commandfactory.h"

CommandFactory::CommandFactory(CustomerIndex* customers, ProductCollection* products){
	//TODO: switch to this constructor instead
	for(int i = 0; i < HASH_TABLE_SIZE; i++){
		commandTemplates[i] = NULL;
	}

	cIndex = customers;
    pCollect = products;

    int historyIndex = hash("H");
	commandTemplates[historyIndex] = new HistoryCMD(customers);
	
	int borrowIndex = hash("B");
	commandTemplates[borrowIndex] = new BorrowCMD(customers, products);

	int returnIndex = hash("R");
	commandTemplates[returnIndex] = new ReturnCMD(customers, products);

	int displayAllIndex = hash("S");
	commandTemplates[displayAllIndex] = new DisplayAllProductCMD(products);
} 

CommandFactory::~CommandFactory(){    // destructor
	
	int historyIndex = hash("H");
	delete commandTemplates[historyIndex];
	commandTemplates[historyIndex] = NULL;
	
	int borrowIndex = hash("B");
	delete commandTemplates[borrowIndex];
	commandTemplates[borrowIndex] = NULL;

	int returnIndex = hash("R");
	delete commandTemplates[returnIndex];
	commandTemplates[returnIndex] = NULL;

	int displayAllIndex = hash("S");
	delete commandTemplates[displayAllIndex] ;
	commandTemplates[displayAllIndex] = NULL;
	
}

// Creates and inits cmd obj based on key given, returns null if invalid key
Command* CommandFactory::create(std::string key){
	int index = hash(key);
	if(commandTemplates[index] != NULL){
		return commandTemplates[index]; //-> create();
	}
	return NULL;
}

int CommandFactory::hash(std::string key){
	return (int) key[0];
}