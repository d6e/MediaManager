#include "historycmd.h"

// default constructor
HistoryCMD::HistoryCMD(CustomerIndex* i, Event* e){
    cIndex = i;
    event = e;
}

HistoryCMD::~HistoryCMD(){}


// Returns false if data invalid, for factory use only.
bool HistoryCMD::setData(Event* e){
    //TODO: figure out whether to fix Event::set so it returns a bool
    event = e;
    return true;
} 


// The execute command will execute the given command from the IO
// It will return true, if the command is found and return ERROR 
// message if the command is not found.
Error HistoryCMD::execute(){
    std::string custID = event->get(1); // The second word is customer ID
    return cIndex->displayHistory(custID);  
}