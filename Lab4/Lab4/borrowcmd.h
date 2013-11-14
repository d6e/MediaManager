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

The BorrowCMD is the default constructor for this class 

The virtual ~BorrowCMD is the default destructor for this class

The execute command will execute the given command from the IO
It will return true, if the command is found and return ERROR 
message if the command is not found.

*/
class BorrowCMD : public Command {
private:
    CustomerIndex* cIndex; //customer Index pointer 
    ProductCollection* mColl; //product collection pointer 
	Event* event;
	int getID(); //Gets the customer ID from the event.

public:
    BorrowCMD(CustomerIndex*,ProductCollection*, Event*); //default constructor
    virtual ~BorrowCMD(); //default destructor 
	// Returns false if data invalid, for factory use only.
    virtual bool setData(Event*); 
    Error execute(); //execute command from the IO 
};

#endif
