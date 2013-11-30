#include "returncmd.h"

//default constructor 
ReturnCMD::ReturnCMD(CustomerIndex* ci, ProductCollection* pc, Event* e){
    cIndex = ci;
    pColl = pc;
    event = e;
}

ReturnCMD::ReturnCMD(CustomerIndex* ci, ProductCollection* pc){
    cIndex = ci;
    pColl = pc;
}


//default destructor 
ReturnCMD::~ReturnCMD(){} 

// Returns false if data invalid, for factory use only.
bool ReturnCMD::setData(Event* e){
	event = e;
    std::string custID = event->get(1); // The second word is customer ID
	cIndex->addTransaction(custID, e);
    return true; //TODO
}

//execute command from the IO 
Error ReturnCMD::execute(){
    return Error(""); //TODO
}