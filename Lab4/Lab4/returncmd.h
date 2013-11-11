#ifndef RETURNCMD_H
#define RETURNCMD_H
#include <string>
#include "customerindex.h"
#include "command.h"

/*
*/
class ReturnCMD : public Command {
private:
    CustomerIndex* cIndex;
    MediaCollection* mColl;
public:
    ReturnCMD(mColl, cInd, custID);
    ~ReturnCMD();
    execute(String);  // Parses string into sections. Checks validity of each section.
        // if customer exists, it adds the transaction to the customer Index
        // calls the mediacollection's return method
    getID() const;
};

#endif