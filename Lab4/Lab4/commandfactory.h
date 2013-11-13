#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H
#include "customerindex.h"
#include "productcollection.h"
#include "command.h"
#include <string>

/*
A factory that produces Commands based on a key to a hashtable containing the different
types of Command objects.

The CommandFactory constructor that takes a CustomerIndex and a ProductCollection
is used to pass along the two data structures to it's products.

The create method takes in a string and parses out the command portion of the
string. It then creates an instance of a child command object based on the 
command it parsed. Finally, it returns a pointer to that command.
*/


class CommandFactory {
public:
	CommandFactory(CustomerIndex, ProductCollection);  // constructor, inits hash table
	virtual ~CommandFactory();    // destructor
    Command* create(std::string key);   // Creates and inits cmd obj based on key given, returns null if invalid key
	
private:
    CustomerIndex* cIndex; // For commands that need access to the customers
    ProductCollection* pCollect; // For commands that need to access the products
	MediaFactory* mFactory; // For commands that need to create products.
	const int HASH_TABLE_SIZE = 256;
	Command* hashTable; // A pointer to an array of Commands implemented as a hash table
	int hash(std::string key);
};

#endif