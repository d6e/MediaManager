#ifndef DISPLAYALLMEDIACMD_H
#define DISPLAYALLMEDIACMD_H
#include <string>
#include "customerindex.h"
#include "mediacollection.h"
#include "command.h"

/*
*/
class DisplayAllMediaCMD : public Command {
private:
    CustomerIndex* cIndex;
    MediaCollection* mColl;
public:
    DisplayAllMediaCMD();
    ~DisplayAllMediaCMD();
    execute();
};

#endif