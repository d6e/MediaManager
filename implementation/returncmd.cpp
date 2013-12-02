#include "returncmd.h"

ReturnCMD::ReturnCMD(CustomerIndex* customers, ProductCollection* products){ // constructor
	//TODO
}

ReturnCMD::ReturnCMD(CustomerIndex* customers, ProductCollection* products, Event* e){ //default constructor
	//TODO
}

ReturnCMD::~ReturnCMD(){} //default destructor 

Command* ReturnCMD::create(){
	//TODO
	return NULL;
	//return new ReturnCMD();
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