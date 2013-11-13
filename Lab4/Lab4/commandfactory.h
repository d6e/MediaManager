#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H
#include "customerindex.h"
#include "productcollection.h"
#include "command.h"
#include <string>

/*
The CommandFactory class parses out the command at the start of the string and creates a product
command based on that command. The rest of the string is passed into the new
command product.

The CommandFactory constructor that takes a CustomerIndex and a ProductCollection
is used to  

*/


class CommandFactory {
private:
    CustomerIndex cIndex;
    ProductCollection mCollect;
public:
    CommandFactory();
	CommandFactory(CustomerIndex, ProductCollection);
	~CommandFactory();
    Command* create(String);
};

#endif