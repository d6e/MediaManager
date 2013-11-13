#ifndef HISTORYCMD_H
#define HISTORYCMD_H
#include <string>
#include "customerindex.h"
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
	Event* event;
public:
    HistoryCMD(CustomerIndex*, Event*);          // default constructor
    virtual ~HistoryCMD();                       // default destructor
    // Returns false if data invalid, for factory use only.
	virtual bool setData(Event*); 
    Error execute(); //execute command from the IO 
};

#endif