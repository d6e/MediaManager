#ifndef COMMAND_H
#define COMMAND_H
#include "customerindex.h"
#include "error.h"
#include "event.h"
#include <string>

/*
The command class is the parent class which all the other commands for the system
inherit from. 

The setData comamnd is for factory use only and is used to insert an event 
object into the new command objects created by the command factory. It returns 
false if the event object passed in is invalid and true otherwise. However, it 
is pure virtual so it doesn't have to be implemented here.

The execute command is pure virtual so doesn't have to be implemented here, but
it is used by the child command objects for executing commands. It returns an
error object depending on whether the method was successful.
*/
class Command {
public:
    Command();          // constructor
    virtual ~Command(); // destructor
	virtual bool setData(Event*) =0; // Returns false if data invalid, for factory use only.
    virtual Error execute() =0; // Returns NULL if no error occured.
};

#endif