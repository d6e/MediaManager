#ifndef DISPLAYALLMEDIACMD_H
#define DISPLAYALLMEDIACMD_H
#include <string>
#include "customerindex.h"
#include "productcollection.h"
#include "command.h"

/*
*/
class DisplayAllMediaCMD : public Command {
private:
    MediaCollection* mColl;
public:
    DisplayAllMediaCMD(MediaCollection* mColl);
    ~DisplayAllMediaCMD();
    Error execute();
};

#endif