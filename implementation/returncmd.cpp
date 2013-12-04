#include "returncmd.h"

ReturnCMD::ReturnCMD(ProductCollection* products, CustomerIndex* customers){ // constructor
	mColl = products;
	cIndex = customers;
}

ReturnCMD::ReturnCMD(ProductCollection* products, CustomerIndex* customers, Event* e){ //default constructor
	mColl = products;
	cIndex = customers;
	event = e;
}

ReturnCMD::~ReturnCMD(){} //default destructor 

Command* ReturnCMD::create(ProductCollection* products
	, CustomerIndex* customers){
	return new ReturnCMD(products, customers);
}

bool ReturnCMD::setData(Event* e){
	event = e;
	return true;
}

Error ReturnCMD::execute(){ //TODO: maybe check for invalid custID?
	Error e = mColl -> makeTransaction(event);
	if(e.getErrorMessage() != ""){
		return e;
	}
    cIndex -> addTransaction(event);	//TODO: add an arg showing that the event is a borrow event
	//TODO: reduce the count of the borrowed movie by 1
	return Error("");
}