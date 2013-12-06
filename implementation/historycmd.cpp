#include "historycmd.h"

// default constructor
HistoryCMD::HistoryCMD(CustomerIndex* i, ProductCollection* pc){ // event is intialized with setdata
    cIndex = i;
}


HistoryCMD::~HistoryCMD(){}


// Returns false if data invalid, for factory use only.
bool HistoryCMD::setData(std::string eventDetails){
    return initArgList(eventDetails);
} 

bool HistoryCMD::initArgList(std::string data){
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

// The execute command will execute the given command from the IO
// It will return true, if the command is found and return ERROR 
// message if the command is not found.
Error HistoryCMD::execute(){
    std::string custID = argList.at(1); // The second word is customer ID
    if(custID == ""){
        return Error("Error: Customer ID is blank");
    }
    cIndex->displayHistory(custID);  
    return Error("");
}