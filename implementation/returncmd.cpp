#include "returncmd.h"

//default constructor 
ReturnCMD::ReturnCMD(CustomerIndex* ci, ProductCollection* pc, Event* e){
    cIndex = ci;
    pColl = pc;
    event = e;
}

//default destructor 
ReturnCMD::~ReturnCMD(){

} 

// Returns false if data invalid, for factory use only.
bool ReturnCMD::setData(Event*){
    return true; //TODO
}

//execute command from the IO 
Error ReturnCMD::execute(){
    return Error(""); //TODO
}