#include "returncmd.h"

//default constructor 
ReturnCMD::ReturnCMD(CustomerIndex* ci, ProductCollection* pc, Event* e){
    cIndex = ci;
    pColl = pc;
    // event = e;
}

ReturnCMD::ReturnCMD(CustomerIndex* ci, ProductCollection* pc){
    cIndex = ci;
    pColl = pc;
}


//default destructor 
ReturnCMD::~ReturnCMD(){} 

// Returns false if data invalid, for factory use only.
bool ReturnCMD::setData(std::string eventDetails){
    initArgList(eventDetails);
    std::string custID = argList.at(1); // The second word is customer ID
    std::string printable = pColl->search(eventDetails); //find the product's parsed version
    if(printable == ""){
        return false;
    }

    Event* e = new Event(eventDetails);//TODO remove set line and put printable in here
    e->set(printable);
	cIndex->addTransaction(custID, e);

    return true; 
}

bool ReturnCMD::initArgList(std::string data){
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
Error ReturnCMD::execute(){
    return Error(""); //TODO
}