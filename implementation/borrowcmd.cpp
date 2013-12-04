#include "borrowcmd.h"

BorrowCMD::BorrowCMD(ProductCollection* products, CustomerIndex* customers){ //constructor
	mColl = products;
	cIndex = customers;
}

BorrowCMD::BorrowCMD(ProductCollection* products, CustomerIndex* customers, Event* e){ //default constructor
	mColl = products;
	cIndex = customers;
	event = e;
}

BorrowCMD::~BorrowCMD(){} //default destructor 

Command* BorrowCMD::create(ProductCollection* products, CustomerIndex* customers){
	return new BorrowCMD(products,customers);
}

// Returns false if data invalid, for factory use only.
bool BorrowCMD::setData(Event* e){
	event = e;
	return true;
} 

Error BorrowCMD::execute(){ //TODO: maybe check for invalid custID?
	Error e = mColl -> makeTransaction(event);
	if(e.getErrorMessage() != ""){
		return e;
	}
    cIndex -> addTransaction(event);
	//TODO: reduce the count of the borrowed movie by 1
	return Error("");
}