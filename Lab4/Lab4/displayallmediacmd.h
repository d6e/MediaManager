#ifndef DISPLAYALLMEDIACMD_H
#define DISPLAYALLMEDIACMD_H
#include <string>
#include "customerindex.h"
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
    execute(String);
};

#endif