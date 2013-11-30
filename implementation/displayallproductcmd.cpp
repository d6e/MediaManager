#include "displayallproductcmd.h"

 // default constructor
DisplayAllProductCMD::DisplayAllProductCMD(ProductCollection* pc){
    pColl = pc;
}

// default destructor
DisplayAllProductCMD::~DisplayAllProductCMD(){

}

// Returns false if data invalid, for factory use only.
bool DisplayAllProductCMD::setData(Event*){
    return true; //TODO
}

//execute command from the IO 
Error DisplayAllProductCMD::execute(){
    return Error(""); //TODO
}