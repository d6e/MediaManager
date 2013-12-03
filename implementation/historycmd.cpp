#include "historycmd.h"

HistoryCMD::HistoryCMD(CustomerIndex* customers){  // constructor
	//TODO
}

HistoryCMD::HistoryCMD(CustomerIndex* customers, Event* e){  // default constructor
	//TODO
}

HistoryCMD::~HistoryCMD(){}  // default destructor

Command* HistoryCMD::create(ProductCollection* products
	, CustomerIndex* customers){
	return new HistoryCMD(customers);
}
   
// Returns false if data invalid, for factory use only.
bool HistoryCMD::setData(Event*){
	//TODO
	return false;
} 

Error HistoryCMD::execute(){ //execute command from the IO 
	Error empty;
	//TODO
	return empty;
}