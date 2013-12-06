#pragma once
#ifndef BORROWCMD_H
#define BORROWCMD_H
#include <string>
#include "customerindex.h"
#include "productcollection.h"
#include "command.h"

/*
The BorrowCMD function will store and verify the borrow 
command from the users. It will output error messages, if 
command is not found and it will execute the command if the 
command exists.
*/

class BorrowCMD : public Command {
private:
    CustomerIndex* cIndex; //customer Index pointer 
    ProductCollection* pColl; //product collection pointer 
	Event* event;
	int getID(); //Gets the customer ID from the event.

public:
    BorrowCMD(CustomerIndex*,ProductCollection*, Event*);
    BorrowCMD(CustomerIndex*,ProductCollection*);
    virtual ~BorrowCMD(); //default destructor 
	// Returns false if data invalid, for factory use only.
    virtual bool setData(Event*); 
    Error execute(); //execute command from the IO 
};

#endif
