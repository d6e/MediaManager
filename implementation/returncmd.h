#pragma once
#ifndef RETURNCMD_H
#define RETURNCMD_H
#include <string>
#include <sstream>
#include <vector>
#include "customerindex.h"
#include "command.h"
#include "productcollection.h"

/*
This class will return the valid command entered by the user
If the command is valid, it will execute the command and return NULL
otherwise it will return error.

The ReturnCMD is the default constructor for this class 

The virtual ~ReturnCMD is the default destructor for this class

The execute command will execute the given command from the IO
It will return true, if the command is found and return ERROR 
message if the command is not found.
*/

class ReturnCMD : public Command {
private:
    CustomerIndex* cIndex; //pointer to the customer index
    ProductCollection* pColl; //pointer to the product collection 
    std::vector<std::string> argList;

public:
    ReturnCMD(CustomerIndex*, ProductCollection*, Event*); //default constructor 
    ReturnCMD(CustomerIndex*, ProductCollection*);
    virtual ~ReturnCMD(); //default destructor 
    // Returns false if data invalid, for factory use only.
	virtual bool setData(std::string); 
	virtual bool initArgList(std::string);

    Error execute(); //execute command from the IO 
};

#endif
