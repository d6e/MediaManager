#include "historycmd.h"

HistoryCMD::HistoryCMD(CustomerIndex* customers){  // constructor
	cIndex = customers;
	event = NULL;
}

HistoryCMD::HistoryCMD(CustomerIndex* customers, Event* e){  // default constructor
	cIndex = customers;
	event = e;
}

HistoryCMD::~HistoryCMD(){	// default destructor
	if(event != NULL){
		//delete event;
		event = NULL;
	}
	if(cIndex != NULL){
		//delete cIndex;
		cIndex = NULL;
	}
}  

Command* HistoryCMD::create(ProductCollection* products, 
CustomerIndex* customers){
	return new HistoryCMD(customers, NULL);
}
   
// Returns false if data invalid, for factory use only.
bool HistoryCMD::setData(Event* e){
	event = e;
    return true;
} 

Error HistoryCMD::execute(){ //execute command from the IO 
	std::string id = event -> getToken(1); 
    return cIndex -> displayHistory(id); 
}