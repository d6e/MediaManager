#ifndef BORROWCMD_H
#define BORROWCMD_H
#include <string>
#include "customerindex.h"
#include "command.h"

/*
*/
class BorrowCMD : public Command {
private:
    CustomerIndex* cIndex;
    MediaCollection* mColl;
public:
    BorrowCMD(mColl, cInd, custID);
    ~BorrowCMD();
    execute(String);// Parses string into sections. Checks validity of each section.
        // if customer exists, it adds the transaction to the customer Index
        // calls the mediacollection's borrow method
    getID() const;
};

#endif