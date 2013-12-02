#ifndef COMMAND_H
#define COMMAND_H
#include "customerindex.h"
#include "error.h"
#include "event.h"
#include <string>

/*
Command class
*/
class Command {
public:
    Command();          
    virtual ~Command(); 
    virtual Command* create() = 0;
    virtual bool setData(Event*) = 0;
    virtual Error execute() = 0;
};
#endif