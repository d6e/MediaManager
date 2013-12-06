#include "borrowcmd.h"

//default constructor
BorrowCMD::BorrowCMD(CustomerIndex* ci,ProductCollection* pc, Event* e){
    cIndex = ci;
    pColl = pc;
    // event = e;
}

BorrowCMD::BorrowCMD(CustomerIndex* ci,ProductCollection* pc){
    cIndex = ci;
    pColl = pc;
}

//default destructor 
BorrowCMD::~BorrowCMD(){}

// Returns false if data invalid, for factory use only.
bool BorrowCMD::setData(std::string eventDetails){
    initArgList(eventDetails);
    std::string custID = argList.at(1); // The second word is customer ID
    std::string printable = pColl->search(eventDetails); //find the product's parsed version
    if(printable == ""){
        return false;
    }

    Event* e = new Event(eventDetails); //TODO remove set line and put printable in here
    e->set(printable);
    cIndex->addTransaction(custID, e);

    return true; 
}

bool BorrowCMD::initArgList(std::string data){
    if(data == ""){
        return false;
    }
    std::string token;
    std::stringstream ss;
    ss << data;
    while (ss >> token)
    {
        argList.push_back(token);
    }
    return true;
}

 //execute command from the IO 
Error BorrowCMD::execute(){
	//TODO: ADD TO HISTORY
    return Error(""); //TODO
}