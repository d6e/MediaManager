#include "returncmd.h"

ReturnCMD::ReturnCMD(ProductCollection* products, CustomerIndex* customers){ // constructor
	//TODO
}

ReturnCMD::ReturnCMD(ProductCollection* products, CustomerIndex* customers, Event* e){ //default constructor
	//TODO
}

ReturnCMD::~ReturnCMD(){} //default destructor 

Command* ReturnCMD::create(ProductCollection* products
	, CustomerIndex* customers){
	return new ReturnCMD(products, customers);
}

bool ReturnCMD::setData(Event* e){
	//TODO
	return false;
}

Error ReturnCMD::execute(){ 
	Error empty;
	//TODO
	return empty;
}