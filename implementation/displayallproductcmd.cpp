#include "displayallproductcmd.h"

DisplayAllProductCMD::DisplayAllProductCMD(ProductCollection* products){  // default constructor
	//TODO
}
 
DisplayAllProductCMD::~DisplayAllProductCMD(){}           // default destructor

Command* DisplayAllProductCMD::create(){
	//TODO
	return NULL;
	//return new DisplayAllProductCMD();
}

// Returns false if data invalid, for factory use only.
bool DisplayAllProductCMD::setData(Event* e){
	//TODO
	return false;
} 

Error DisplayAllProductCMD::execute(){	//execute command from the IO 
	Error empty;
	//TODO
	return empty;
}  