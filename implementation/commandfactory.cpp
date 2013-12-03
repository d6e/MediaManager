#include "commandfactory.h"

CommandFactory::CommandFactory(CustomerIndex* customers, ProductCollection* products){
	for(int i = 0; i < HASH_TABLE_SIZE; i++){
		commandTemplates[i] = NULL;
	}

    int historyIndex = hash("H");
	commandTemplates[historyIndex] = new HistoryCMD(customers);
	
	int borrowIndex = hash("B");
	commandTemplates[borrowIndex] = new BorrowCMD(products, customers);

	int returnIndex = hash("R");
	commandTemplates[returnIndex] = new ReturnCMD(products, customers);

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
Command* CommandFactory::create(std::string key, ProductCollection* products,
	CustomerIndex* customers){
	int index = hash(key);
	if(commandTemplates[index] != NULL){
		return commandTemplates[index] -> create(products, customers);
	}
	return NULL;
}

int CommandFactory::hash(std::string key){
	return (int) key[0];
}