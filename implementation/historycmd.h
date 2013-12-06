#pragma once
#ifndef HISTORYCMD_H
#define HISTORYCMD_H
#include <string>
#include <sstream>
#include "customerindex.h"
#include "command.h"

/*
Displays history of a customer in terms of all events
associated with them.
*/

class HistoryCMD : public Command {    
private:
    CustomerIndex* cIndex;
	Event* event;
public:
	HistoryCMD(CustomerIndex*); // event is intialized with setdata
    HistoryCMD(CustomerIndex*, Event*);         
    virtual ~HistoryCMD();                       // default destructor
    // Returns false if data invalid, for factory use only.
	virtual bool setData(Event*); 
    Error execute(); //execute command from the IO 
};

#endif