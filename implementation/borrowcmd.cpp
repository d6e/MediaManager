#include "borrowcmd.h"

BorrowCMD::BorrowCMD(ProductCollection* products, CustomerIndex* customers){ //constructor
	//TODO
}

BorrowCMD::BorrowCMD(ProductCollection* products, CustomerIndex* customers, Event* e){ //default constructor
	//TODO
}

BorrowCMD::~BorrowCMD(){} //default destructor 

Command* BorrowCMD::create(ProductCollection* products, CustomerIndex* customers){
	return new BorrowCMD(products,customers);
}

// Returns false if data invalid, for factory use only.
bool BorrowCMD::setData(Event* e){
	//TODO
	return false;
} 

Error BorrowCMD::execute(){ //execute command from the IO 
	Error empty;
	//TODO
	return empty;
}

int BorrowCMD::getID(){ //Gets the customer ID from the event.
	//TODO
	return 0;
}