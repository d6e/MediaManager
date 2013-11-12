#ifndef BORROWCMD_H
#define BORROWCMD_H
#include <string>
#include "customerindex.h"
#include "mediacollection.h"
#include "command.h"

/*
The BorrowCMD function will store and verify the borrow 
command from the users. It will output error messages, if 
command is not found and it will execute the command if the 
command exists.

The BorrowCMD is the default constructor for this class 
The ~BorrowCMD is the default destructor for this class
The execute command will execute the given command from the IO
It will return true, if the command is found and return ERROR 
message if the command is not found.
The getID is a function that will return the customer ID 

*/
class BorrowCMD : public Command {
private:

    CustomerIndex* cIndex; //customer Index pointer 
    MediaCollection* mColl; //media collection pointer 

public:

    BorrowCMD(mColl, cInd, custID); //default constructor
    ~BorrowCMD(); //default destructor 
    bool execute(); //execute command from the IO 
    int getID() const; //get the customer ID 
};

#endif
