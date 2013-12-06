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
bool DisplayAllProductCMD::setData(std::string eventDetails){
    return initArgList(eventDetails);
} 

bool DisplayAllProductCMD::initArgList(std::string data){
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
Error DisplayAllProductCMD::execute(){
	pColl->displayAll();
    return Error(""); //TODO
}