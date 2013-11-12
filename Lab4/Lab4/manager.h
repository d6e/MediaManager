#ifndef MANAGER_H
#define MANAGER_H
#include "customerindex.h"
#include "mediacollection.h"
#include "commandfactory.h"
#include "mediafactory.h"
#include "error.h"
#include <string>

/*
The manager class is the main controller for the program.
*/

class Manager{

private:
    CustomerIndex customerDB;
    MediaCollection mediaDB;
    CommandFactory cFactory;
    MediaFactory mFactory;

public:
	Manager(); //Initializes all collections and factories
	~Manager();
	
	Bool inputMedia(string);
    Bool inputCustomer(string);
    Bool inputCmd(string);
	 // {    // pseudocode for inputCmd
     //     Command CMD = CommandFactory.create(arg)
     //     cmd.execute
     //     delete cmd
     // }
};

#endif