#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H
#include "customerindex.h"
#include "productcollection.h"
#include "command.h"
#include <string>

/*
A factory that produces Commands based on a key to a hashtable containing the different
types of Command objects.
*/
class CommandFactory {

public:
	CommandFactory(CustomerIndex, ProductCollection);  // constructor, inits hash table
	~CommandFactory();    // destructor
    Command* create(string key);   // Creates and inits cmd obj based on key given, returns null if invalid key
	
private:
    CustomerIndex cIndex;
    ProductCollection pCollect;
	const int HASH_TABLE_SIZE = 256;
	Command* hashTable; // A pointer to an array of Commands implemented as a hash table
	int hash(string key);
};

#endif