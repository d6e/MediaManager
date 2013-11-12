#ifndef MANAGER_H
#define MANAGER_H
#include "customerindex.h"
#include "mediacollection.h"
#include "commandcontrol.h"
#include "commandfactory.h"
#include "error.h"
#include <string>

/*
The manager class is the main controller for the program.
*/

class Manager{

private:
    CustomerIndex customerDB;
    MediaCollection mediaDB;
    CustomerFactory cFactory;
    MediaFactory mFactory;
    CommandControl controls;
    Bool inputMedia(string);
    Bool inputCustomer(string);
    Bool initCmd();
    Bool inputCmd(string);
        // {    // pseudocode for inputCmd
        //     Command CMD = CommandFactory.create(arg)
        //     cmd.execute
        //     delete cmd
        // }

public:
	Manager();
	~Manager();
};

#endif