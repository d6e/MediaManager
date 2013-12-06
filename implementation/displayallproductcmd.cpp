#include "displayallproductcmd.h"

 // default constructor
DisplayAllProductCMD::DisplayAllProductCMD(CustomerIndex* ci, ProductCollection* pc){
    cIndex = ci;
    pColl = pc;
}

// default destructor
DisplayAllProductCMD::~DisplayAllProductCMD(){

}

// Returns false if data invalid, for factory use only.
bool DisplayAllProductCMD::setData(Event* e){
	event = e;
	// ADD EVENT TO HISTORY
    std::string custID = event->get(1); // The second word is customer ID
	cIndex->addTransaction(custID, e);
    return true; 
}

//execute command from the IO 
Error DisplayAllProductCMD::execute(){
	pColl->displayAll();
    return Error(""); 
}