#include "displayallproductcmd.h"

 // default constructor
DisplayAllProductCMD::DisplayAllProductCMD(ProductCollection* pc){
    pColl = pc;
}

// default destructor
DisplayAllProductCMD::~DisplayAllProductCMD(){

}

// Returns false if data invalid, for factory use only.
bool DisplayAllProductCMD::setData(Event* e){
	event = e;
	// ADD EVENT TO HISTORY
	 //    std::string custID = event->get(1); // The second word is customer ID
		// cIndex->addTransaction(custID, e);
    return true; //TODO: Not sure if need. Might want to add event to history
}

//execute command from the IO 
Error DisplayAllProductCMD::execute(){
    return Error(""); //TODO
}