#include "historycmd.h"

// default constructor
HistoryCMD::HistoryCMD(CustomerIndex* i, Event* e){
    cIndex = i;
    event = e;
}

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
    //TODO: figure out if this is where the data should be parsed or not
    std::string custID = event->get(0);

    cIndex->displayHistory(custID);  
    return Error("This is the execute command.");
}