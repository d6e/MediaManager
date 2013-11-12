#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H
#include "customerindex.h"
#include "mediacollection.h"
#include "command.h"
#include <string>

/*
Parses string command and input and sets it up so the product commands only
have to read 
*/

class CommandFactory {
private:
    CustomerIndex cIndex;
    MediaCollection mCollect;
public:
    CommandFactory();
	CommandFactory(CustomerIndex, MediaCollection);
	~CommandFactory();
    Command* create(String);
};

#endif