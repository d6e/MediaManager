#ifndef DISPLAYALLMEDIACMD_H
#define DISPLAYALLMEDIACMD_H
#include <string>
#include "customerindex.h"
#include "productcollection.h"
#include "command.h"

/*
*/
class DisplayAllProductCMD : public Command {
private:
    ProductCollection* mColl;
public:
    DisplayAllProductCMD(ProductCollection* mColl);
    ~DisplayAllProductCMD();
    Error execute();
};

#endif