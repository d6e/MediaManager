#ifndef HISTORYCMD_H
#define HISTORYCMD_H
#include <string>
#include "customerindex.h"
#include "command.h"

/*
Displays history of a customer in terms of all events
associated with them.
Deletes event when destructed.	
*/
class HistoryCMD : public Command {    
private:
    CustomerIndex* cIndex;
	Event* event;
public:
    HistoryCMD(CustomerIndex*, Event*);
    ~HistoryCMD();
	virtual bool setData(Event*); // Returns false if data invalid, for factory use only.
    Error execute(); 
};

#endif