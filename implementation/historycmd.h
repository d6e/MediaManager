#pragma once
#ifndef HISTORYCMD_H
#define HISTORYCMD_H
#include <string>
#include <sstream>
#include <vector>
#include "customerindex.h"
#include "productcollection.h"
#include "command.h"

/*
Displays history of a customer in terms of all events
associated with them.

The HistoryCMD is the default constructor for this class.

The virtual ~HistoryCMD is the default destructor for this class.

The execute command will execute the given command from the IO
It will return true, if the command is found and return ERROR 
message if the command is not found.
*/
class HistoryCMD : public Command {    
private:
    CustomerIndex* cIndex;
	std::vector<std::string> argList;
public:
	HistoryCMD(CustomerIndex*, ProductCollection*); // event is intialized with setdata
    // HistoryCMD(CustomerIndex*, Event*);          // default constructor
    virtual ~HistoryCMD();                       // default destructor
    // Returns false if data invalid, for factory use only.
	virtual bool setData(std::string); 
	virtual bool initArgList(std::string);

    Error execute(); //execute command from the IO 
};

#endif