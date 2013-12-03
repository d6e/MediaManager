#ifndef COMMAND_H
#define COMMAND_H
#include "productcollection.h"
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
    virtual Command* create(ProductCollection*,CustomerIndex*) = 0;
    virtual bool setData(Event*) = 0;
    virtual Error execute() = 0;
};
#endif