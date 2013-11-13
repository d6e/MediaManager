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
is used to pass along the two data structures to it's products.

The create method takes in a string and parses out the command portion of the
string. It then creates an instance of a child command object based on the 
command it parsed. Finally, it returns a pointer to that command.
*/


class CommandFactory {
private:
    CustomerIndex cIndex;
    ProductCollection mCollect;
public:
    CommandFactory();   // Constructor
	CommandFactory(CustomerIndex, ProductCollection);  // constructor
	~CommandFactory();    // destructor
    Command* create(string);   // Creates and inits cmd obj based on string
};

#endif