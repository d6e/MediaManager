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

The DisplayAllProductCMD is the default constructor for this class 

The virtual ~DisplayAllProductCMD is the default destructor for this class

The execute command will execute the given command from the IO
It will return true, if the command is found and return ERROR 
message if the command is not found.

*/
class DisplayAllProductCMD : public Command {
private:
    ProductCollection* mColl;
public:
    DisplayAllProductCMD(ProductCollection*);  // default constructor
    virtual ~DisplayAllProductCMD();           // default destructor
    // Returns false if data invalid, for factory use only.
	virtual bool setData(Event); 
    Error execute();  //execute command from the IO 
};

#endif