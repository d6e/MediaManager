#pragma once
#ifndef COMMAND_H
#define COMMAND_H
#include "customerindex.h"
#include "error.h"
#include "event.h"
#include <string>

/*
The command class is the parent class which all the other commands for the 
system inherit from. 
*/
class Command {
public:
    Command();          // constructor
    virtual ~Command(); // destructor
     // Returns false if data invalid, for factory use only.
	virtual bool setData(Event*) =0;
    virtual Error execute() =0; // Returns NULL if no error occured.
};

#endif