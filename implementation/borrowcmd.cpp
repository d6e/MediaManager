#include "borrowcmd.h"



BorrowCMD::BorrowCMD(CustomerIndex* customers,ProductCollection* products){ //constructor
	//TODO
}

BorrowCMD::BorrowCMD(CustomerIndex* customers,ProductCollection* products, Event* e){ //default constructor
	//TODO
}

BorrowCMD::~BorrowCMD(){} //default destructor 

Command* BorrowCMD::create(){
	//TODO
	return NULL;
	//return new BorrowCMD();
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