#ifndef MANAGER_H
#define MANAGER_H
#include <string>
#include "customerindex.h"
#include "mediacollection.h"
#include "commandcontrol.h"
#include "error.h"

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
    Error inputMedia(String);
    Error inputCustomer(String);
    Error initCmd();
    Error inputCmd(String);

public:
	Manager();
	~Manager();
};

#endif