#pragma once
#ifndef RETURNCMD_H
#define RETURNCMD_H
#include <string>
#include "customerindex.h"
#include "command.h"
#include "productcollection.h"

/*
This class will return the valid command entered by the user
If the command is valid, it will execute the command and return NULL
otherwise it will return error.
*/

class ReturnCMD : public Command {
private:
    CustomerIndex* cIndex; //pointer to the customer index
    ProductCollection* pColl; //pointer to the product collection 
    Event* event; // pointer to entire command information.

public:
    ReturnCMD(CustomerIndex*, ProductCollection*, Event*); 
    ReturnCMD(CustomerIndex*, ProductCollection*);
    virtual ~ReturnCMD(); //default destructor 
    // Returns false if data invalid, for factory use only.
	virtual bool setData(Event*); 
    Error execute(); //execute command from the IO 
};

#endif
