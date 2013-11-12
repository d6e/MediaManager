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
	String mediaInfo;
public:
    ReturnCMD(mColl, cInd, custID, mediaInfo);
    ~ReturnCMD();
    execute();
};

#endif