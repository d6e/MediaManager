#pragma once
#ifndef DISPLAYALLPRODUCTCMD_H
#define DISPLAYALLPRODUCTCMD_H
#include <string>
#include "customerindex.h"
#include "productcollection.h"
#include "command.h"

/*
Displays all products by thier type (catagory) and sorted by thier unique 
crtieria. Also displays how many items were borrowed, how many remain.
Deletes event when destructed.
*/

class DisplayAllProductCMD : public Command {
private:
    ProductCollection* pColl;
    CustomerIndex* cIndex;
    Event* event;
public:
    DisplayAllProductCMD(CustomerIndex*,ProductCollection*);
    virtual ~DisplayAllProductCMD();           // default destructor
    // Returns false if data invalid, for factory use only.
	virtual bool setData(Event*); 
    Error execute();  //execute command from the IO 
};

#endif