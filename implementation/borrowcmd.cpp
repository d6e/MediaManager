#include "borrowcmd.h"

//default constructor
BorrowCMD::BorrowCMD(CustomerIndex* ci,ProductCollection* pc, Event* e){
    cIndex = ci;
    pColl = pc;
    event = e;
}

BorrowCMD::BorrowCMD(CustomerIndex* ci,ProductCollection* pc){
    cIndex = ci;
    pColl = pc;
}

//default destructor 
BorrowCMD::~BorrowCMD(){}

// Returns false if data invalid, for factory use only.
bool BorrowCMD::setData(Event* e){
    event = e;
    std::string custID = event->get(1); // The second word is customer ID
	cIndex->addTransaction(custID, e);
    return true; //TODO
}

 //execute command from the IO 
Error BorrowCMD::execute(){
	//TODO: ADD TO HISTORY
    return Error(""); //TODO
}