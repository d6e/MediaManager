#ifndef RETURNCMD_H
#define RETURNCMD_H
#include <string>
#include "customerindex.h"
#include "command.h"

/*
This class will return the valid command entered by the user
If the command is valid, it will execute the command and return NULL
 otherwise it will return error.
*/

class ReturnCMD : public Command {
private:
    CustomerIndex* cIndex; //pointer to the customer index
    ProductCollection* mColl; //pointer to the product collection 
    Event* event; // pointer to entire command information.

public:
    ReturnCMD(CustomerIndex*, ProductCollection*, Event*); //default constructor 
    ~ReturnCMD(); //default destructor 
	virtual bool setData(Event); // Returns false if data invalid, for factory use only.
    Error execute(); //validate the cmd input 
};

#endif
