#ifndef RETURNCMD_H
#define RETURNCMD_H
#include <string>
#include "customerindex.h"
#include "command.h"

/*
This class will return the valid command entered by the user
If the command is valid, it will execute the command otherwise 
it will return error 

ReturnCMD is the default constructor for this class, it will create 
a ReturnCMD object 

~ReturnCMD is the default constructor 

execute function checks the valid input, return error for an invalid 
command and execute the command if it is valid 
*/

class ReturnCMD : public Command {
private:

    CustomerIndex* cIndex; //pointer to the customer index
    ProductCollection* mColl; //pointer to the product collection 
    String productInfo; //variable to store the variable info 

public:
    ReturnCMD(mColl, cInd, custID, productInfo); //default constructor 
    ~ReturnCMD(); //default destructor 
    bool execute(); //validate the cmd input 
};

#endif
