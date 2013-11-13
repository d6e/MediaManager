#ifndef COMMAND_H
#define COMMAND_H
#include "customerindex.h"
#include "error.h"
#include <string>

/*
A command executes some operation on the system.
*/
class Command {
public:
    Command();
    virtual ~Command();
	virtual bool setData(Event*) =0; // Returns false if data invalid, for factory use only.
    virtual Error execute() =0; // Returns NULL if no error occured.
};

#endif