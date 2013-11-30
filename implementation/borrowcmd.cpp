#include "borrowcmd.h"

//default constructor
BorrowCMD::BorrowCMD(CustomerIndex* ci,ProductCollection* pc, Event* e){
    cIndex = ci;
    pColl = pc;
    event = e;
}

//default destructor 
BorrowCMD::~BorrowCMD(){

}

// Returns false if data invalid, for factory use only.
bool BorrowCMD::setData(Event*){
    return true; //TODO
}

 //execute command from the IO 
Error BorrowCMD::execute(){
    return Error(""); //TODO
}