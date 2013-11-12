#ifndef BORROWCMD_H
#define BORROWCMD_H
#include <string>
#include "customerindex.h"
#include "mediacollection.h"
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
    execute();
    getID() const;
};

#endif