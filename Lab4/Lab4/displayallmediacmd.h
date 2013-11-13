#ifndef DISPLAYALLPRODUCTCMD_H
#define DISPLAYALLPRODUCTCMD_H
#include <string>
#include "customerindex.h"
#include "productcollection.h"
#include "command.h"

/*
Displays all products by thier type (catagory) and sorted by thier unique crtieria.
Also displays how many items were borrowed, how many remain.
Deletes event when destructed.
*/
class DisplayAllProductCMD : public Command {
private:
    ProductCollection* mColl;
public:
    DisplayAllProductCMD(ProductCollection*);
    virtual ~DisplayAllProductCMD();
	virtual bool setData(Event); // Returns false if data invalid, for factory use only.
    Error execute();
};

#endif